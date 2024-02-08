#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are
adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/
class Solution
{
public:
	void sortColors(vector<int> &nums) 
	{
		if (nums.size() == 1) return;

		int low = 0;
		int high = nums.size() - 1;

		for (int i = 0; i <= high;) 
		{
			if (nums[i] == 0) 
			{
				swap(nums[low++], nums[i++]);
			}
			else if (nums[i] == 2)
			{
				swap(nums[high--], nums[i]);
			}
			else
			{
				i++;
			}
		}
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::sortColors);
}
#endif