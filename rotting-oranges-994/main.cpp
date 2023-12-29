#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
You are given an m x n grid where each cell can have one of three values:

	0 representing an empty cell,
	1 representing a fresh orange, or
	2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return
-1.
*/

class Solution
{
public:
	int bfs(vector<vector<int>> &grid, int i, int j, queue<pair<int, int>> &rotten)
	{
		int fresh = 0;
		if (i + 1 >= 0 && j >= 0 && i + 1 < grid.size() && j < grid[0].size() && grid[i + 1][j] == 1)
		{
			grid[i + 1][j] = 2;
			rotten.push({i + 1, j});
			fresh++;
		}
		if (i - 1 >= 0 && j >= 0 && i - 1 < grid.size() && j < grid[0].size() && grid[i - 1][j] == 1)
		{
			grid[i - 1][j] = 2;
			rotten.push({i - 1, j});
			fresh++;
		}
		if (i >= 0 && j + 1 >= 0 && i < grid.size() && j + 1 < grid[0].size() && grid[i][j + 1] == 1)
		{
			grid[i][j + 1] = 2;
			rotten.push({i, j + 1});
			fresh++;
		}
		if (i >= 0 && j - 1 >= 0 && i < grid.size() && j - 1 < grid[0].size() && grid[i][j - 1] == 1)
		{
			grid[i][j - 1] = 2;
			rotten.push({i, j - 1});
			fresh++;
		}
		return fresh;
	}
	int orangesRotting(vector<vector<int>> &grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		queue<pair<int, int>> rotten;
		int fresh = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 2)
				{
					rotten.push({i, j});
				}
				else if (grid[i][j] == 1)
					fresh++;
			}
		}
		int minTime = -1;
		while (!rotten.empty())
		{
			int currentSize = rotten.size();
			for (int t = 0; t < currentSize; t++)
			{
				auto current = rotten.front();
				rotten.pop();
				fresh -= bfs(grid, current.first, current.second, rotten);
			}
			minTime += 1;
		}
		if (fresh > 0)
			return -1;
		if (minTime == -1)
			return 0;
		return minTime;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::orangesRotting);
}
#endif