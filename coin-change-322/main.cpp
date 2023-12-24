#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
You are given an integer array coins representing coins of different denominations and an integer amount representing a
total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any
combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

class Solution
{
      public:
	int coinChange(vector<int> &coins, int amount)
	{
		vector<int> dp(amount + 1, INT_MAX);
		dp[0] = 0;

		for (int coin : coins)
		{
			for (int i = coin; i <= amount; ++i)
			{
				if (dp[i - coin] != INT_MAX)
				{
					//cout << dp[i - coin] + 1 << " " << dp[i] <<endl;
					dp[i] = min(dp[i], dp[i - coin] + 1);
				}
			}
		}

		return (dp[amount] == INT_MAX) ? -1 : dp[amount];
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::coinChange);
}
#endif