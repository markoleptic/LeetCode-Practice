#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the
original letters exactly once.
*/
class Solution
{
      public:
	bool isAnagram(string s, string t)
	{
		unordered_map<char, int> letterMap;
		for (char c : s)
		{
			letterMap[c] += 1;
		}
		for (char c : t)
		{
			if (!letterMap.contains(c))
				return false;
			letterMap[c] -= 1;
			if (letterMap[c] < 0)
				return false;
		}
		for (auto elem : letterMap)
		{
			if (elem.second != 0)
				return false;
		}
		return true;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::isAnagram);
}
#endif