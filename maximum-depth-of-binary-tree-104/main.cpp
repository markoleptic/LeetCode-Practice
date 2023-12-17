#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf
node.
*/
class Solution
{
      public:
	int maxDepth(TreeNode *root)
	{
		if (!root)
			return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return 1 + max(left, right);
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::maxDepth);
}
#endif