#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an m x n matrix, return all elements of the matrix in spiral order.
*/
class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix)
	{
		// this is so bad
		vector<int> out;
		int m = matrix.size();
		int n = matrix[0].size();
		std::pair<int, int> startRight = { 0, 0};
		std::pair<int, int> endRight = { 0, n - 1};
		std::pair<int, int> startDown = { 1, n - 1};
		std::pair<int, int> endDown = { m - 1, n - 1};
		std::pair<int, int> startLeft = { m - 1, n - 2};
		std::pair<int, int> endLeft = { m - 1, 0};
		std::pair<int, int> startUp  = { m - 2, 0};
		std::pair<int, int> endUp  = { 1, 0 };
		while (out.size() < m * n)
		{
			for (int j = startRight.second; j <= endRight.second; j++)
			{
				out.push_back(matrix[startRight.first][j]);
			}
	
			for (int i = startDown.first; i <= endDown.first; i++)
			{
				out.push_back(matrix[i][startDown.second]);
			}
			if (startRight.first == startLeft.first)
				if (endRight.second > endLeft.second)
					break;
			for (int j = startLeft.second; j >= endLeft.second; j--)
			{
				out.push_back(matrix[startLeft.first][j]);
			}
			if (startDown.second == startUp.second)
				if (endDown.first > endUp.first)
					break;
			for (int i = startUp.first; i >= endUp.first; i--)
			{
				out.push_back(matrix[i][startUp.second]);
			}
			
			startDown.first++;
			endDown.first--;
			startDown.second--;
			startLeft.second--;
			endLeft.second++;
			startLeft.first--;
			startRight.second++;
			endRight.second--;
			startRight.first++;
			startUp.first--;
			endUp.first++;
			startUp.second++;
		}
		return out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::spiralOrder);
}
#endif