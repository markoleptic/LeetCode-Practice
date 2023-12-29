#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such
that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For
example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or
-1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution
{
public:
	int pivotSearch(const vector<int> &nums, int start, int end)
	{
		// no pivot
		if (nums[start] <= nums[end])
			return -1;

		int mid = start + (end - start) / 2;
		if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1])
			return mid + 1;

		// pivot to the right side
		if (nums[mid] > nums[end])
			return pivotSearch(nums, mid, end);
		// pivot to the left side
		return pivotSearch(nums, start, mid);
	}
	int binarySearch(const vector<int> &nums, int start, int end, int target)
	{
		if (start > end)
			return -1;
		int mid = start + (end - start) / 2;
		if (nums[mid] == target)
			return mid;
		if (nums[mid] < target)
			return binarySearch(nums, mid + 1, end, target);
		else
			return binarySearch(nums, start, mid - 1, target);
	}
	int search(vector<int> &nums, int target)
	{
		if (nums.size() == 1)
			return (nums[0] == target) ? 0 : -1;
		int pivot = pivotSearch(nums, 0, nums.size() - 1);
		if (pivot == -1)
			return binarySearch(nums, 0, nums.size() - 1, target);
		int leftSearch = binarySearch(nums, 0, pivot - 1, target);
		int rightSearch = binarySearch(nums, pivot, nums.size() - 1, target);
		if (leftSearch != -1)
			return leftSearch;
		return rightSearch;
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