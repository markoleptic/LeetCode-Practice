#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

static int findClosestZero(const vector<std::pair<int, int>> &zeroLocations, int i, int j)
{
	int minIDist = 99999;
	int minJDist = 99999;
	int minI = 99999;
	int minJ = 99999;
	for (auto it = zeroLocations.begin(); it != zeroLocations.end(); ++it)
	{
		int currIDist = abs(it->first - i);
		int currJDist = abs(it->second - j);
		if ((currIDist + currJDist) < (minIDist + minJDist))
		{
			minIDist = currIDist;
			minI = it->first;
			minJDist = currJDist;
			minJ = it->second;
		}
		if ((minIDist + minJDist) == 1)
			return 1;
	}
	return minIDist + minJDist;
}

/**
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
*/
class Solution
{
      public:
	vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
	{
		vector<vector<int>> out(mat.size(), vector<int>(mat[0].size(), 0));
		vector<std::pair<int, int>> zeroLocations;
		for (int i = 0; i < mat.size(); ++i)
		{
			for (int j = 0; j < mat[i].size(); ++j)
			{
				if (mat[i][j] == 0)
				{
					zeroLocations.push_back({i, j});
				}
			}
		}
		for (int i = 0; i < mat.size(); ++i)
		{
			for (int j = 0; j < mat[i].size(); ++j)
			{
				if (mat[i][j] == 0)
					continue;
				out[i][j] = findClosestZero(zeroLocations, i, j);
			}
		}
		return out;
	}

	// DP approach
      public:
	vector<vector<int>> updateMatrixDP(vector<vector<int>> &mat)
	{
		int m = mat.size(), n = mat[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j] == 0)
				{
					continue;
				}
				int top = m + n, left = m + n;
				if (i - 1 >= 0)
					top = mat[i - 1][j];
				if (j - 1 >= 0)
					left = mat[i][j - 1];
				mat[i][j] = min(top, left) + 1;
			}
		}
		for (int i = m - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (mat[i][j] == 0)
				{
					continue;
				}
				int bottom = m + n, right = m + n;
				if (i + 1 < m)
					bottom = mat[i + 1][j];
				if (j + 1 < n)
					right = mat[i][j + 1];
				mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
			}
		}
		return mat;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::updateMatrix);
}
#endif