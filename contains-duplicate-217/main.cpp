#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every
element is distinct.
*/
class Solution
{
      public:
	bool containsDuplicate(vector<int> &nums)
	{
		int N = nums.size();
		std::unordered_map<int, int> Histo;
		for (int i = 0; i < N; ++i)
		{
			auto result = Histo.emplace(nums[i], 0);
			if (!result.second)
			{
				return true;
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
	exec(&Solution::containsDuplicate);
}
#endif