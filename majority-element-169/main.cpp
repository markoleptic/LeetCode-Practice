#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element
always exists in the array.
*/
class Solution
{
      public:
	int majorityElement(vector<int> &nums)
	{
		int count = 0;
		int candidate = 0;
		for (auto num : nums)
		{
			if (count == 0)
			{
				candidate = num;
			}
			count += (candidate == num) ? 1 : -1;
		}
		count = 0;
		for (auto num : nums)
		{
			if (candidate == num)
			{
				count++;
			}
		}
		return (count > nums.size() / 2) ? candidate : -1;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::majorityElement);
}
#endif