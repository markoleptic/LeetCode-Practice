#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

struct closePoint
{
	std::pair<int, int> point;
	double dist;

	closePoint(const std::pair<int, int> &inPair, double inDist)
	{
		point = inPair;
		dist = inDist;
	}

	bool operator<(const closePoint &other) const { return dist < other.dist; }
};

/**
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k
closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
*/
class Solution
{
      public:
	vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
	{
		std::priority_queue<closePoint> closestPoints;
		int m = points.size();
		for (int i = 0; i < m; i++)
		{
			int x = points[i][0];
			int y = points[i][1];
			double dist = sqrt(x * x + y * y);
			closestPoints.push(closePoint({x, y}, dist));
			if (closestPoints.size() > k)
			{
				closestPoints.pop();
			}
		}
		vector<vector<int>> out;
		while (!closestPoints.empty())
		{
			out.push_back({closestPoints.top().point.first, closestPoints.top().point.second});
			closestPoints.pop();
		}
		return out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::kClosest);
}
#endif