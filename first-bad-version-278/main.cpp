#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

static int binarySearch(int start, int end)
{
	if (start > end)
		return -1;

	int mid = start + (end - start) / 2;

	if (isBadVersion(mid))
		// if mid is bad, check if its the first bad version
		if (mid == start || !isBadVersion(mid - 1))
		{
			return mid;
		}
		else
		{
			return binarySearch(start, mid - 1);
		}
	else
	{
		return binarySearch(mid + 1, end);
	}
}
/**
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of
your product fails the quality check. Since each version is developed based on the previous version, all the versions
after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following
ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the
first bad version. You should minimize the number of calls to the API.
*/
class Solution
{
      public:
	int firstBadVersion(int n) { return binarySearch(1, n); }
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::firstBadVersion);
}
#endif