#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/

// recursive template:
// vector<int> current;
// for (int i = 0; i < nums.size(); i++)
// {
// 	current.push_back({nums[i]});
// 	out.push_back(current);
// 	for (int j = i + 1; j < nums.size(); j++)
// 	{
// 		current.push_back({nums[j]});
// 		out.push_back(current);
// 		for (int k = j + 1; k < nums.size(); k++)
// 		{
// 			current.push_back({nums[k]});
// 			out.push_back(current);
// 			current.pop_back();
// 		}
// 		current.pop_back();
// 	}
// 	current.pop_back();
// }

class Solution
{
public:
	void recurse(vector<int> &nums, int start, vector<int> &current, vector<vector<int>> &out)
	{
		out.push_back(current);
		for (int i = start; i < nums.size(); i++)
		{
			current.push_back(nums[i]);
			recurse(nums, i + 1, current, out);
			current.pop_back();
		}
	}

	vector<vector<int>> subsets(vector<int> &nums)
	{
		vector<vector<int>> out;
		vector<int> current;
		recurse(nums, 0, current, out);
		return out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::subsets);
}
#endif