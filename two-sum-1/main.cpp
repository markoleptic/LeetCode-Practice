#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to
target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
class Solution
{
      public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++)
		{
			int complement = target - nums[i];
			if (map.contains(complement))
				return {map.at(complement), i};
			map.emplace(nums[i], i);
		}
		return std::vector<int>(2);
	}

	vector<int> twoSumTwoPointer(vector<int> &nums, int target)
	{
		vector<pair<int, int>> pairs(nums.size());

		for (int i = 0; i < nums.size(); i++) 
		{
			pairs[i] = {nums[i], i};
		}

		std::sort(pairs.begin(), pairs.end());

		int left = 0;
		int right = nums.size() - 1;

		while (left < right) 
		{
			int current = pairs[left].first + pairs[right].first;
			if (current == target)
			{
				return { pairs[left].second, pairs[right].second };
			}
			if (current < target) 
			{
				left++;
			}
			else 
			{
				right--;
			}
		}
		return {};
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::twoSum);
}
#endif