#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/*
Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and
columns are 0-indexed).
*/
class Solution
{
      public:
	int numSpecial(vector<vector<int>> &mat)
	{
		int num = 0;
		for (int i = 0; i < mat.size(); ++i)
		{
			int oneIndex = -1;
			for (int j = 0; j < mat[i].size(); ++j)
			{
				if (mat[i][j] == 1)
				{
					if (oneIndex != -1)
					{
						oneIndex = -1;
						break;
					}
					oneIndex = j;
				}
				else if (mat[i][j] != 0)
				{
					oneIndex = -1;
					break;
				}
			}
			if (oneIndex != -1)
			{
				for (int k = 0; k < mat.size(); ++k)
				{
					if (k == i)
						continue;
					if (mat[k][oneIndex] != 0)
					{
						oneIndex = -1;
						break;
					}
				}
			}
			if (oneIndex != -1)
				num++;
		}
		return num;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::numSpecial);
}
#endif