#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

static void invertSubtree(TreeNode *node)
{
	if (!node)
		return;

	TreeNode *temp = node->left;
	node->left = node->right;
	node->right = temp;

	invertSubtree(node->left);
	invertSubtree(node->right);
}

/*
Given the root of a binary tree, invert the tree, and return its root.
*/
class Solution
{
      public:
	TreeNode *invertTree(TreeNode *root)
	{
		invertSubtree(root);
		return root;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::invertTree);
}
#endif