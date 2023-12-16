#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

static int getNodeDepth(TreeNode *node)
{
	if (!node)
		return 0;
	int left = getNodeDepth(node->left);
	int right = getNodeDepth(node->right);
	return 1 + max(left, right);
}

/**
Given a binary tree, determine if it is height-balanced.
*/
class Solution
{
      public:
	bool isBalanced(TreeNode *root)
	{
		if (!root)
			return true;

		int leftHeight = getNodeDepth(root->left);
		int rightHeight = getNodeDepth(root->right);

		if (abs(leftHeight - rightHeight) > 1)
			return false;

		bool leftBalanced = isBalanced(root->left);
		bool rightBalanced = isBalanced(root->left);

		return leftBalanced && rightBalanced;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::isBalanced);
}
#endif