#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start
and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval
newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still
does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.
*/
class Solution
{
      public:
	vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
	{
		// insert new interval based on start interval
		bool bInserted = false;
		for (auto it = intervals.begin(); it != intervals.end(); ++it)
		{
			if (newInterval[0] < it->at(0))
			{
				intervals.insert(it, newInterval);
				bInserted = true;
				break;
			}
		}
		if (!bInserted)
			intervals.push_back(newInterval);

		// merge overlapping intervals, set old intervals to -1
		auto previous = intervals.begin();
		for (auto it = intervals.begin() + 1; it != intervals.end(); ++it)
		{
			if (previous->at(1) >= it->at(0))
			{
				it->at(0) = std::min(previous->at(0), it->at(0));
				it->at(1) = std::max(previous->at(1), it->at(1));
				previous->at(0) = -1;
				previous->at(1) = -1;
			}
			previous = it;
		}
		intervals.erase(std::remove_if(intervals.begin(), intervals.end(),
					       [&](const vector<int>& elem) { return elem[0] == -1; }),
				intervals.end());
		return intervals;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::insert);
}
#endif