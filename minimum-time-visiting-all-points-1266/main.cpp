#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/*
On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. Return the minimum time in seconds to
visit all the points in the order given by points.

You can move according to these rules:

    In 1 second, you can either:
	move vertically by one unit,
	move horizontally by one unit, or
	move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
    You have to visit the points in the same order as they appear in the array.
    You are allowed to pass through points that appear later in the order, but these do not count as visits.

*/
class Solution
{
      public:
	int minTimeToVisitAllPoints(vector<vector<int>> &points)
	{
		if (points.size() == 1)
			return 0;

		int Total = 0;
		for (int i = 1; i < points.size(); i++)
		{
			int xDiff = std::abs(points[i - 1][0] - points[i][0]);
			int yDiff = std::abs(points[i - 1][1] - points[i][1]);
			// std::cout << "xDiff: " << xDiff << " yDiff: " << yDiff << std::endl;

			int NonDiagonal = std::abs(xDiff - yDiff);
			Total += (NonDiagonal + std::min(xDiff, yDiff));
		}
		return Total;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::minTimeToVisitAllPoints);
}
#endif