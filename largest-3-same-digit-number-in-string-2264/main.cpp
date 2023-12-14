#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif
/*
You are given a string num representing a large integer. An integer is good if it meets the following conditions:

    It is a substring of num with length 3.
    It consists of only one unique digit.

Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

    A substring is a contiguous sequence of characters within a string.
    There may be leading zeroes in num or a good integer.

*/
class Solution
{
      public:
	string largestGoodInteger(string num)
	{
		int Goodest = -1;
		string GoodestString = "";
		for (int i = 2; i < num.length(); ++i)
		{
			string Substring = num.substr(i - 2, 3);
			if (Substring[0] == Substring[1] && Substring[1] == Substring[2])
			{
				int IntString = std::stoi(Substring);
				if (IntString > Goodest)
				{
					Goodest = IntString;
					GoodestString = Substring;
				}
			}
		}
		return GoodestString;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::largestGoodInteger);
}
#endif