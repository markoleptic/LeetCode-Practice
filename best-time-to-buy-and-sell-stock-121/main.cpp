#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to
sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
class Solution
{
      public:
	int maxProfit(vector<int> &prices)
	{
		if (prices.empty())
			return 0;

		int minPrice = prices[0];
		int max = 0;

		for (size_t i = 1; i < prices.size(); ++i)
		{
			const int current = prices[i];
			if (current < minPrice)
			{
				minPrice = current;
			}
			else
			{
				max = std::max(max, current - minPrice);
			}
		}
		return max;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::maxProfit);
}
#endif