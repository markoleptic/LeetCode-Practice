#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/
class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> out(numRows);
		out[0].push_back(1);
		for (int i = 1; i < numRows; ++i)
		{
			out[i].push_back(1);
			if (i > 1)
				for (int j = 1; j < i; ++j)
				{
					// cout << "i-1: " << i - 1 << " j-1: " << j - 1 << " j+1: " << j << endl;
					out[i].push_back(out[i - 1][j - 1] + out[i - 1][j]);
				}
			if (numRows > 1)
			{
				out[i].push_back(1);
			}
		}
		return out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::generate);
}
#endif