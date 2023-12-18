#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given a string s, find the length of the longest substring without repeating characters.
*/
class Solution
{
      public:
	int lengthOfLongestSubstring(string s)
	{
		std::map<char, int> letterMap;
		int maxLength = 0;
		int left = 0;

		for (int right = 0; right < s.size(); ++right)
		{
			char currentChar = s[right];
			if (letterMap.find(currentChar) != letterMap.end())
			{
				if (letterMap[currentChar] >= left)
					left = letterMap[currentChar] + 1;
			}
			letterMap[currentChar] = right;
			maxLength = std::max(maxLength, right - left + 1);
		}

		return maxLength;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::lengthOfLongestSubstring);
}
#endif