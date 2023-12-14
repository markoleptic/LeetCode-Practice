#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/*
Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the
day before. On every subsequent Monday, he will put in $1 more than the previous Monday.

Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.
*/
class Solution
{
      public:
	int totalMoney(int n)
	{
		vector<int> days = {1, 2, 3, 4, 5, 6, 7};
		int non_remainder = n / 7;
		int remainder = n % 7;
		int total = 0;
		for (int i = 1; i <= n; i += 7)
		{
			days.push_back(days.size() + 1);
		}
		for (int i = 0; i < non_remainder; i++)
		{
			for (int j = i; j < i + 7; j++)
			{
				total += days[j];
			}
		}
		for (int i = 0; i < remainder; i++)
		{
			total += days[non_remainder + i];
		}
		return total;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::totalMoney);
}
#endif