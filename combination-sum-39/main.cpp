#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of
candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the
frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150
combinations for the given input.
*/
class Solution
{
public:
	void backtrack(vector<int> &candidates, int target, int start, vector<int> &currentCombos, vector<vector<int>> &combos)
	{
        if (target == 0)
        {
            combos.push_back(currentCombos);
            return;
        }
		for (int i = start; i < candidates.size(); i++)
		{
			cout << "i=" << i << ": ";
			for (int j = 0; j < currentCombos.size(); j++)
			{
				cout << currentCombos[j] << " ";
			}
			cout << " candidate: " << candidates[i] << endl;

			if (candidates[i] > target) continue;
			currentCombos.push_back(candidates[i]);

			// continue with same candidate since repeats
			backtrack(candidates, target - candidates[i], i, currentCombos, combos);

            // Exclude the current candidate from the combination (backtrack)
            currentCombos.pop_back();
		}
	}
    
	vector<vector<int>> combinationSum(vector<int> &candidates, int target)
	{
		vector<int> currentCombo;
		vector<vector<int>> combos;
		backtrack(candidates, target, 0, currentCombo, combos);
		return combos;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::combinationSum);
}
#endif