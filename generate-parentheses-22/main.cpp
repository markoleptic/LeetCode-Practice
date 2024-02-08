#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/
class Solution
{
	void recurse(vector<string>& v, string str, int left, int right)
	{
		//cout << str << " " << left  << " " << right << endl;
		if (left == 0 && right == 0)
		{
			v.push_back(str);
			return;
		}

		if (left > 0) recurse(v, str + "(", left - 1, right + 1);
		if (right > 0) recurse(v, str + ")", left, right - 1);
	}
      public:
    vector<string> generateParenthesis(int n) 
	{
		vector<string> out;
        recurse(out, "", n, 0);
		return out;
    }
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::generateParenthesis);
}
#endif