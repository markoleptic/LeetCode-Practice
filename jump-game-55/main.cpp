#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/
class Solution
{
      public:
    bool canJump(vector<int>& nums) 
	{
        int lastIdx = nums.size() - 1;
        int maxReach = 0;

        for (int i = 0; i <= lastIdx; ++i) {
            if (i > maxReach) 
			{
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);

			cout << i << " " << maxReach << endl;

            if (maxReach >= lastIdx) 
			{
                return true;
            }
        }

        return false;
    }
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::canJump);
}
#endif