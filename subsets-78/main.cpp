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
	void doLoop(int start, vector<int>& nums, vector<vector<int>>& out, vector<int>& current)
	{
		current.push_back({nums[start]});
		out.push_back(current);
		for (int i = start + 1; i < nums.size(); i++)
		{
			doLoop(i, nums, out, current);
		}
		current.pop_back();
	}

    vector<vector<int>> subsets(vector<int>& nums) 
	{
		vector<vector<int>> out;
		out.push_back({});
		for (int i = 0; i < nums.size(); i++)
		{
			vector<int> prevLoopValues;
			doLoop(i, nums, out, prevLoopValues);
		}
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