#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you
can see ordered from top to bottom.
*/
class Solution
{
public:
	void traverseBFS(TreeNode *node)
	{
		queue<TreeNode *> nodeQueue;
		nodeQueue.push(node);
		while (!nodeQueue.empty())
		{
			TreeNode *current = nodeQueue.front();
			nodeQueue.pop();
			if (current->left)
				nodeQueue.push(current->left);
			if (current->right)
				nodeQueue.push(current->right);
		}
	}

	vector<int> rightSideView(TreeNode *root)
	{
		vector<int> out;
		if (!root)
			return out;
		queue<pair<TreeNode *, int>> nodeQueue;
		map<int, int> depthMap;
		int depth = 0;
		nodeQueue.push({root, depth});
		while (!nodeQueue.empty())
		{
			TreeNode *current = nodeQueue.front().first;
			depth = nodeQueue.front().second;
			nodeQueue.pop();

			depthMap[depth] = current->val;
			// cout << current->val << " " << depth <<" " << endl;

			if (current->left)
				nodeQueue.push({current->left, depth + 1});
			if (current->right)
				nodeQueue.push({current->right, depth + 1});
		}
		for (auto elem : depthMap)
		{
			out.push_back(elem.second);
		}
		return out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::rightSideView);
}
#endif