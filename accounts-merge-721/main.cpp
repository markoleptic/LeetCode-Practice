#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is
a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common
email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people
could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have
the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name,
and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
*/

class Solution
{
public:
	vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) 
	{
		map<string, string> owner;
        map<string, string> parents;
		int numAccs = accounts.size();

        for (int i = 0; i < numAccs; i++) 
		{
            for (int j = 1; j < accounts[i].size(); j++) 
			{
				string email = accounts[i][j];
				// Each email is initially its own parent
                parents[email] = email; 
                owner[email] = accounts[i][0];
            }
        }

		for (int i = 0; i < numAccs; i++) 
		{
			string firstEmail = accounts[i][1];
			// Find the root/representative of the first email
            string root = find(firstEmail, parents);
            for (int j = 2; j < accounts[i].size(); j++)
			{
				// Update parent pointers to the root
 				parents[find(accounts[i][j], parents)] = root;
			}
        }

		// Create unions of emails based on their root representatives
		map<string, set<string>> unions;
		for (int i = 0; i < numAccs; i++)
            for (int j = 1; j < accounts[i].size(); j++)
                unions[find(accounts[i][j], parents)].insert(accounts[i][j]);

        vector<vector<string>> res;
        for (pair<string, set<string>> p : unions) 
		{
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
	}
	private:
	// finding the root representative of an element using path compression
	string find(string str, map<string, string>& inMap)
	{
		return inMap[str] == str ? str : find(inMap[str], inMap);
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::accountsMerge);
}
#endif