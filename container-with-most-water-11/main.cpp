#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int best = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int current = std::min(height[left], height[right]) * (right - left);
            best = max(best, current);
            if (height[left] >  height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return best;
    }
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::maxArea);
}
#endif