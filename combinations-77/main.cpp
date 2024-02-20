#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
*/
class Solution
{
public:
	void recurse(int maxRange, int k, vector<int> &current, int index, vector<vector<int>> &out)
	{
		if (current.size() == k)
		{
			out.push_back(current);
			return;
		}
		for (int i = index; i <= maxRange; i++)
		{
			current.push_back(i);
			recurse(maxRange, k, current, i + 1, out);
			current.pop_back();
		}
	}

	vector<vector<int>> combine(int n, int k)
	{
		vector<int> nums;
		for (int i = 1; i <= n; i++)
		{
			nums.push_back(i);
		}
		vector<vector<int>> out;
		vector<int> current;
		recurse(n, k, current, 1, out);
		return out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::combine);
}
#endif