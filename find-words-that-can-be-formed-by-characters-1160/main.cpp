#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.
*/
class Solution
{
      public:
	int countCharacters(vector<string> &words, string chars)
	{
		std::unordered_map<char, int> Map;
		int NumGood = 0;
		for (int i = 0; i < chars.length(); ++i)
		{
			Map[chars[i]] += 1;
		}
		for (int i = 0; i < words.size(); ++i)
		{
			std::unordered_map<char, int> TempMap(Map);
			bool bGood = true;
			for (auto Letter : words[i])
			{
				auto Found = TempMap.find(Letter);
				if (Found == TempMap.end())
				{
					bGood = false;
					break;
				}
				Found->second -= 1;
			}
			if (bGood)
				for (auto &x : TempMap)
				{
					if (x.second < 0)
					{
						bGood = false;
						break;
					}
				}
			if (bGood)
				NumGood += words[i].length();
		}
		return NumGood;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::countCharacters);
}
#endif