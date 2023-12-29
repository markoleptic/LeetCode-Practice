#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/
class Solution {
public:
	void backtrack(vector<int> &nums, map<int, int>& visited, vector<int> &currentCombos, vector<vector<int>> &combos)
	{
        if (currentCombos.size() == nums.size())
        {
            combos.push_back(currentCombos);
            return;
        }
		for (int i = 0; i < nums.size(); i++)
		{
			cout << "i=" << i << ": ";
			for (int j = 0; j < currentCombos.size(); j++)
			{
				cout << currentCombos[j] << " ";
			}
			cout << " candidate: " << nums[i] << endl;
			if (visited[i] == 0)
			{
				currentCombos.push_back(nums[i]);
				visited[i] = 1;
				backtrack(nums, visited, currentCombos, combos);
				visited[i] = 0; 
				currentCombos.pop_back();
			}
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
		vector<int> current;
		map<int, int> visited;
		backtrack(nums, visited, current, permutations);
		return permutations;
    }
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::permute);
}
#endif