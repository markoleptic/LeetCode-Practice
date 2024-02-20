#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int LocalMax = nums[0];
        int GlobalMax = nums[0];
		std::cout << "LocalMax: " << LocalMax << " GlobalMax: " << GlobalMax << std::endl;
        for (int i = 1; i < nums.size(); ++i) 
        {
            int Value = nums[i];
            LocalMax = std::max(Value, Value + LocalMax);
            GlobalMax = std::max(GlobalMax, LocalMax);
            std::cout << "LocalMax: " << LocalMax << " GlobalMax: " << GlobalMax << std::endl;
        }
        return GlobalMax;
    }
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::maxSubArray); // CHANGE FOR PROBLEM
}
#endif