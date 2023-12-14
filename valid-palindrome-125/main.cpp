#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif
#include <algorithm>
#include <cctype>

static string removeNonAlphaNumericAndToLower(const string &input)
{
	string result;
	for (char ch : input)
	{
		if (isalnum(ch))
		{
			result.push_back(ch);
		}
	}
	transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return tolower(c); });
	return result;
}

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all
non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and
numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/
class Solution
{
      public:
	bool isPalindrome(string s)
	{
		string newS = removeNonAlphaNumericAndToLower(s);
		string reversedS = newS;
		cout << newS << endl;
		reverse(reversedS.begin(), reversedS.end());
		return reversedS == newS;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::isPalindrome);
}
#endif