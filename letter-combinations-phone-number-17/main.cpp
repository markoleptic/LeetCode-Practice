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
	map<char, vector<char>> letterMap;
	void doLoop(vector<string> &out, int index, const string &digits, string &str)
	{
		if (str.length() == digits.size())
		{
			out.push_back(str);
			return;
		}
		for (int i = 0; i < letterMap[digits[index]].size(); i++)
		{
			str += letterMap[digits[index]][i];
			doLoop(out, index + 1, digits, str);
			str.erase(str.end() - 1);
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
		doLoop(out, 0, digits, str);
		return out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::letterCombinations);
}
#endif