#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could
represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any
letters.
*/
class Solution
{
	void recurse(const string &digits, int index, string &current, vector<string> &out)
	{
		// termination condition; add to out vector
		if (current.length() == digits.size())
		{
			out.push_back(current);
			return;
		}
		for (int i = 0; i < letterMap[digits[index]].size(); i++)
		{
			// add a new letter to current
			current += letterMap[digits[index]][i];
			// recursively call for next index in digits
			recurse(digits, index + 1, current, out);
			// remove the added letter
			current.erase(current.end() - 1);
		}
	}

public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> out;
		if (digits.empty())
			return out;

		letterMap['2'] = {'a', 'b', 'c'};
		letterMap['3'] = {'d', 'e', 'f'};
		letterMap['4'] = {'g', 'h', 'i'};
		letterMap['5'] = {'j', 'k', 'l'};
		letterMap['6'] = {'m', 'n', 'o'};
		letterMap['7'] = {'p', 'q', 'r', 's'};
		letterMap['8'] = {'t', 'u', 'v'};
		letterMap['9'] = {'w', 'x', 'y', 'z'};

		string str;
		recurse(digits, 0, str, out);
		return out;
	}

	map<char, vector<char>> letterMap;
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::letterCombinations);
}
#endif