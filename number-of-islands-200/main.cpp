#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume
all four edges of the grid are all surrounded by water.
*/



class Solution
{
public:
	void dfs(int i, int j, vector<vector<char>> &grid)
	{
		if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 || grid[i][j] == '0')
		{
			return;
		}
		grid[i][j] = '0';
		dfs(i + 1, j, grid);
		dfs(i - 1, j, grid);
		dfs(i, j + 1, grid);
		dfs(i, j - 1, grid);
	}
	int numIslands(vector<vector<char>> &grid) 
	{
		int m = grid.size();
		int n = grid[0].size();
		int num = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == '1')
				{
					dfs(i, j, grid);
					num++;
				}
			}
		}
		return num;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::numIslands);
}
#endif