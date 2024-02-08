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
		string currentSubstring;

		for (int i = 0; i < s.length(); i++) 
		{
			char currentChar = s[i];
			letterMap[currentChar] += 1;

			if (letterMap[currentChar] == 1)
			{
				currentSubstring += currentChar;
				maxLength = std::max(maxLength, static_cast<int>(currentSubstring.length()));
			}
			else
			{
				int pos = currentSubstring.find_last_of(currentChar);
				//cout << currentSubstring << " ";
				for (int j = 0; j <= pos; j++)
				{
					letterMap[currentSubstring[j]]--;
				}
				currentSubstring.erase(0, pos + 1);
				currentSubstring += currentChar;
				//cout << currentSubstring << endl;
			}
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