#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of
the non-overlapping intervals that cover all the intervals in the input.
*/
class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
		std::sort(intervals.begin(), intervals.end());
		if (intervals.size() == 1)
			return intervals;
		int m = intervals.size();
		vector<vector<int>> newIntervals;
		for (int i = 0; i < m;)
		{
			vector<int> currentInterval;
			int start = intervals[i][0];
			int end = intervals[i][1];
			currentInterval.push_back(start);

			int j = i + 1;
			while (j < m)
			{
				int testStart = intervals[j][0];
				int testEnd = intervals[j][1];
				if (testStart <= end)
				{
					end = max(testEnd, end);
				}
				else
				{
					break;
				}
				j++;
			}
			currentInterval.push_back(end);
			newIntervals.push_back(currentInterval);
			i = j;
		}
		return newIntervals;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::merge);
}
#endif