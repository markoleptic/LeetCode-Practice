#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/
class Solution
{
public:
	// recursive solution
	bool isMirrorRecurse(TreeNode *node1, TreeNode *node2)
	{
		if (!node1 && !node2)
		{
			return true;
		}
		if (!node1 || !node2)
		{
			return false;
		}
		return node1->val == node2->val && isMirrorRecurse(node1->left, node2->right) && isMirrorRecurse(node1->right, node2->left);
	}

	// BFS iterative solution
	bool isMirrorBFS(TreeNode* root)
	{
		if (!root)
			return true;

		queue<TreeNode *> q;
		q.push(root);
		q.push(root);

		while (!q.empty())
		{
			TreeNode *leftNode = q.front();
			q.pop();
			TreeNode *rightNode = q.front();
			q.pop();

			if (!leftNode && !rightNode)
				continue;
			if (!leftNode || !rightNode)
				return false;
			if (leftNode->val != rightNode->val)
				return false;

			q.push(leftNode->left);
			q.push(rightNode->right);
			q.push(leftNode->right);
			q.push(rightNode->left);
		}
		return true;
	}

	bool isSymmetric(TreeNode *root)
	{
		if (!root) return true;
		// return isMirrorBFS(root);
		return isMirrorRecurse(root->left, root->right);
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::isSymmetric);
}
#endif