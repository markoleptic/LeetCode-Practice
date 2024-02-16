#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given a string s, return the longest palindromic substring in s.
*/
class Solution
{
public:
	string longestPalindrome(string s) 
	{
		string longest;
		if (s.length() == 1) return s;
		if (s.length() == 2) return s[0] == s[1] ? s : s.substr(0, 1);

		for (int i = 0; i < s.length(); i++)
		{
			int left = i, right = i + 1;
			while (left >= 0 && right < s.length())
			{
				if (s[left] == s[right]) 
				{
					if (right - left + 1 > longest.length())
					{
						longest = s.substr(left, right - left + 1);
					}
				}
				else
				{
					break;
				}
				left--;
				right++;
			}

			if (i + 2 < s.length())
			{
				left = i;
				right = i + 2;
				while (left >= 0 && right < s.length())
				{
					if (s[left] == s[right]) 
					{
						if (right - left + 1 > longest.length())
						{
							longest = s.substr(left, right - left + 1);
						}
					}
					else
					{
						break;
					}
					left--;
					right++;
				}
			}
		}
		if (longest.length() == 0) return s.substr(0, 1);
		return longest;
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