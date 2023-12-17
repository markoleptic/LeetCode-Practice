#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif
#include "algorithm"

/**
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can
be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
*/
class Solution
{
      public:
	int longestPalindrome(string s)
	{
		unordered_map<char, int> letterMap;
		for (char c : s)
		{
			letterMap[c] += 1;
		}
		if (letterMap.size() == 1) return letterMap.begin()->second;

		unordered_map<char, int> evens;
		unordered_map<char, int> odds;
		char largestOddChar;
		int largestOddCharNum = 0;
		
		for (auto elem : letterMap)
		{
			bool bDivisibleByTwo = elem.second % 2 == 0;
			if (!bDivisibleByTwo)
			{
				if (elem.second > 1) {
					odds[elem.first] = elem.second;
				}
				if (largestOddCharNum < elem.second) 
				{
					largestOddChar = elem.first;
					largestOddCharNum = elem.second;
				}
			}
			else if (bDivisibleByTwo)
			{
				evens[elem.first] = elem.second;
			}
		}
		odds.erase(largestOddChar);

		int total = 0;
		for (auto elem : evens)
		{
			total += elem.second;
		}
		for (auto elem : odds)
		{
			total += elem.second - 1;
		}
		return total + largestOddCharNum;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::longestPalindrome);
}
#endif