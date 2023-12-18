#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

static void traverse(TreeNode *node, vector<vector<int>> &nodes, int depth)
{
	if (!node)
		return;

	if (depth > (int)nodes.size() - 1)
	{
		nodes.resize(nodes.size() + 1);
	}

	nodes[depth].push_back(node->val);
	traverse(node->left, nodes, depth + 1);
	traverse(node->right, nodes, depth + 1);
}

/**
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level
by level).
*/
class Solution
{
      public:
	vector<vector<int>> levelOrder(TreeNode *root)
	{
		vector<vector<int>> nodes;
		traverse(root, nodes, 0);
		return nodes;
	}

	vector<vector<int>> levelOrderWithQueue(TreeNode *root)
	{
		vector<vector<int>> nodes;
		if (!root)
			return nodes;

		queue<TreeNode *> nodeQueue;
		nodeQueue.push(root);

		while (!nodeQueue.empty())
		{
			vector<int> currentNodeValues;
			int nodeSize = nodeQueue.size();

			for (int i = 0; i < nodeSize; i++)
			{
				TreeNode *node = nodeQueue.front();
				nodeQueue.pop();
				currentNodeValues.push_back(node->val);

				if (node->left)
				{
					nodeQueue.push(node->left);
				}
				if (node->right)
				{
					nodeQueue.push(node->right);
				}
			}
			nodes.push_back(currentNodeValues);
		}

		return nodes;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::levelOrderWithQueue);
}
#endif