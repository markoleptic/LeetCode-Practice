#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif
/**
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.
*/
class Solution
{
      public:
	int maxProduct(vector<int> &nums)
	{
		int LocalMax = nums[0];
		int LocalMin = nums[0];
		int GlobalMax = nums[0];
		std::cout << LocalMax << " : "  << LocalMin << " : " << GlobalMax << std::endl;
		for (int i = 1; i < nums.size(); ++i)
		{
			int Value = nums[i];

			if (Value < 0)
			{
				std::swap(LocalMax, LocalMin);
			}

			LocalMax = std::max(Value, LocalMax * Value);
			LocalMin = std::min(Value, LocalMin * Value);
			GlobalMax = std::max(LocalMax, GlobalMax);

			std::cout << nums[i] << " : "  << LocalMax << " : "  << LocalMin << " : " << GlobalMax << std::endl;
		}
		return GlobalMax;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::maxProduct);
}
#endif