#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

class Solution
{
public:
	// DFS
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		if ((!p && q) || (p && !q))
			return false;

		if (!p && !q)
			return true;

		if (p->val != q->val)
			return false;

		bool leftSame = isSameTree(p->left, q->left);
		bool rightSame = isSameTree(p->right, q->right);

		return leftSame && rightSame;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::isSameTree);
}
#endif