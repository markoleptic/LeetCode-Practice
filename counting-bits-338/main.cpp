#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's
in the binary representation of i.
*/
class Solution
{
public:

	int bitCount_TopDown(vector<int> &bits, int n)
	{
		if (bits[n] != -1)
			return bits[n];
		else
		{
			bits[n] = (n & 1) + bitCount_TopDown(bits, n >> 1);
		}
		return bits[n];
	}

	std::vector<int> bitCount_BottomUp(std::vector<int> &bits, int n)
	{
		for (int i = 0; i <= n; ++i)
		{
			if (i == 0)
			{
				bits[i] = 0;
			}
			else if (bits[i] == -1)
			{
				// cout << i << " & 1 = " << (i & 1) << ", " << i << " >> 1 = " << (i >> 1) <<  endl;
				int isOdd = (i & 1);
				bits[i] = isOdd + bits[i >> 2];
				// same as bits[i] = (i % 2 != 0) + bits[i / 2];
			}
		}
		return bits;
	}

	std::vector<int> countBits(int n)
	{
		std::vector<int> bits(n + 1, -1);
		// bits[0] = 0;
		// for (int i = 1; i <= n; ++i)
		// {
		// 	bitCount_TopDown(bits, i);
		// }
		// return bits;
		return bitCount_BottomUp(bits, n);
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::countBits);
}
#endif