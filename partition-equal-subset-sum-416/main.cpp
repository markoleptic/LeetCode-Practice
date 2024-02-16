#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the
elements in both subsets is equal or false otherwise.
*/
class Solution
{
public:
	bool canPartition(vector<int> &nums)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2 != 0)
			return false;

		int target = sum / 2;

		unordered_set<int> possibleSums;
		possibleSums.insert(0);

		for (int num : nums)
		{
			unordered_set<int> updatedSums(possibleSums);
			for (int currentSum : possibleSums)
			{
				int newSum = currentSum + num;
				if (newSum == target)
				{
					return true;
				}
				if (newSum < target)
				{
					updatedSums.insert(newSum);
				}
			}
			possibleSums = updatedSums;
			for (auto elem : possibleSums)
			{
				cout << elem << endl;
			}
		}
		return false;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::canPartition);
}
#endif