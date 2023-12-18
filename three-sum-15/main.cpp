#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
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

	vector<vector<int>> threeSum(vector<int> &nums)
	{
		vector<vector<int>> out;
		int n = nums.size();
		if (n < 3)
			return out;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			int requiredTwoSum = 0 - nums[i];
			int left = i + 1;
			int right = n - 1;
			while (left < right)
			{
				int sum = nums[left] + nums[right];
				if (sum == requiredTwoSum)
				{
					out.push_back({nums[i], nums[left], nums[right]});
					while (left < right && nums[left] == nums[left + 1])
					{
						++left;
					}
					while (left < right && nums[right] == nums[right - 1])
					{
						--right;
					}
					++left;
					--right;
				}
				else if (sum < requiredTwoSum)
				{
					++left;
				}
				else
				{
					--right;
				}
			}
		}
		return out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::threeSum);
}
#endif