#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif
/**
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of
nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/
class Solution
{
      public:
	vector<int> productExceptSelf(vector<int> &nums)
	{
		int N = nums.size();

		std::vector<int> Left(N, 1);
		std::vector<int> Right(N, 1);
		std::vector<int> Out(N, 1);

		int CurrentProductLeft = 1;
		int CurrentProductRight = 1;

		for (int i = 1; i < N; ++i)
		{
			CurrentProductLeft *= nums[i - 1];
			Left[i] = CurrentProductLeft;

			CurrentProductRight *= nums[N - i];
			Right[N - i - 1] = CurrentProductRight;
		}

		for (int i = 0; i < N; ++i)
		{
			Out[i] = Left[i] * Right[i];
		}
		return Out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::productExceptSelf);
}
#endif