#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from
magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
*/
class Solution
{
      public:
	bool canConstruct(string ransomNote, string magazine)
	{
		unordered_map<char, int> letterMap;
		for (char c : magazine)
		{
			letterMap[c] += 1;
		}
		for (char c : ransomNote)
		{
			if (!letterMap.contains(c))
				return false;
			letterMap[c] -= 1;
		}
		for (auto elem : letterMap)
		{
			if (elem.second < 0) return false;
		}
		return true;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::canConstruct);
}
#endif