#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/
class Solution
{
public:
	void backtrack(vector<int> &nums, map<int, int> &visited, vector<int> &current, vector<vector<int>> &out)
	{
		if (current.size() == nums.size())
		{
			out.push_back(current);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (visited[i] == 1)
				continue;
			current.push_back(nums[i]);
			visited[i] = 1;
			backtrack(nums, visited, current, out);
			current.pop_back();
			visited[i] = 0;
		}
	}

	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int>> permutations;
		vector<int> current;
		map<int, int> visited;
		backtrack(nums, visited, current, permutations);
		return permutations;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::permute);
}
#endif