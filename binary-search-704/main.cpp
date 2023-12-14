#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

static int binarySearch(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
        return -1;

    int mid = start + (end - start) / 2;

	if (nums[mid] == target)
		return mid;
	if (nums[mid] < target)
	{
		return binarySearch(nums, mid + 1, end, target);
	}
	else
	{
		return binarySearch(nums, start, mid - 1, target);
	}
}

/**
Given an array of integers nums which is sorted in ascending order,
and an integer target, write a function to search target in nums.
If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.
*/
class Solution
{
      public:
	int search(vector<int> &nums, int target)
	{
		return binarySearch(nums, 0, nums.size() - 1, target);
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::search);
}
#endif