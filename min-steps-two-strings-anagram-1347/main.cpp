#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
You are given two strings of the same length s and t. In one step you can choose any character of t and replace it with
another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.
*/
class Solution
{
public:
	int minSteps(string s, string t)
	{
		map<char, int> letterMap;
		int strSize = s.length();
		for (char c : s)
		{
			letterMap[c] += 1;
		}
		for (char c : t)
		{
			if (letterMap.contains(c) && letterMap[c] > 0)
			{
				strSize -= 1;
				letterMap[c] -= 1;
			}
		}
		return strSize;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::minSteps);
}
#endif