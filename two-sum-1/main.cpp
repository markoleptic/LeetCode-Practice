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
		std::vector<int> Out(2);
		for (size_t i = 0; i < nums.size() - 1; i++)
		{
			for (size_t j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					Out[0] = i;
					Out[1] = j;
					return Out;
				}
			}
		}
		return Out;
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