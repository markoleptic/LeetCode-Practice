#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given two binary strings a and b, return their sum as a binary string.
*/
class Solution
{
      public:
	int addChars(string strA, string strB, int strIndex, string &out, string &rem)
	{
		char a = strA[strIndex];
		char b = strB[strIndex];
		char c = rem[strIndex];
		if (strIndex < 0 || strIndex >= strA.length())
			return 1;
		if (a == '1' && b == '1')
		{
			out[strIndex] = (c == '0') ? '0' : '1';
			if (strIndex - 1 < 0)
				return 1;
			rem[strIndex - 1] = 1;
		}
		else if ((a == '1' || b == '1'))
		{
			if (c == '0')
			{
				out[strIndex] = '1';
			}
			else
			{
				out[strIndex] = '0';
				if (strIndex - 1 < 0)
					return 1;
				rem[strIndex - 1] = 1;
			}
		}
		else
		{
			out[strIndex] = (c == '0') ? '0' : '1';
		}
		return 0;
	}

	string addBinary(string a, string b)
	{
		if (a.length() > b.length())
		{
			while (b.length() != a.length())
			{
				b = '0' + b;
			}
		}
		else
		{
			while (b.length() != a.length())
			{
				a = '0' + a;
			}
		}

		b = '0' + b;
		a = '0' + a;

		string out(b.length(), '0');
		string rem(b.length(), '0');

		int res = 0;
		for (int i = b.length() - 1; i >= 0; i--)
		{
			res = addChars(a, b, i, out, rem);
		}
		if (res > 0)
		{
			b = '0' + b;
			a = '0' + a;
			out = '0' + out;
			res = '0' + res;
			addChars(a, b, 1, out, rem);
		}
		while (out.size() > 1)
		{
			if (out[0] == '0')
				out.erase(0, 1);
			else
				break;
		}
		return out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::addBinary);
}
#endif