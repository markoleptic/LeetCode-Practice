#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
class Solution
{
      public:
	int climbStairs(int n)
	{
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		if (n == 3)
			return 3;
		vector<int> ways(n, 0);
		ways[0] = 1;
		ways[1] = 2;
		for (int i = 2; i < n; ++i)
		{
			int nMinus1 = ways[i - 1];
			int nMinus2 = ways[i - 2];
			ways[i] = nMinus1 + nMinus2;
		}
		return ways[n-1];
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::climbStairs);
}
#endif