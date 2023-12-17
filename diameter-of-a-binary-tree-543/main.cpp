#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

int getNodeDepth(TreeNode *node)
{
	if (!node)
		return 0;
	int left = getNodeDepth(node->left);
	int right = getNodeDepth(node->right);
	return 1 + max(left, right);
}

int inOrder(TreeNode *node, int maxDepth)
{
	if (!node)
		return maxDepth;
	int depth = getNodeDepth(node->left) + getNodeDepth(node->right);
	depth = inOrder(node->left, max(depth, maxDepth));
	depth = inOrder(node->right, max(depth, maxDepth));
	return max(depth, maxDepth);
}

/**
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may
not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/
class Solution
{
      public:
	int diameterOfBinaryTree(TreeNode *root)
	{
		if (!root)
			return 0;
		return inOrder(root, 0);
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::diameterOfBinaryTree);
}
#endif