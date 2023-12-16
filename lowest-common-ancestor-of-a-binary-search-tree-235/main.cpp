#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

static void createPath(TreeNode *node, int target, vector<int> &path)
{
	if (!node)
		return;

	path.push_back(node->val);
	if (node->val == target)
		return;
	if (node->val > target) 
		createPath(node->left, target, path);
	if (node->val < target) 
		createPath(node->right, target, path);
}

static TreeNode *descendTree(TreeNode *node, int target)
{
	if (!node)
		return nullptr;
	if (node->val == target)
		return node;
	if (node->val > target)
		return descendTree(node->left, target);
	if (node->val < target)
		return descendTree(node->right, target);
	return nullptr;
}

/**
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the
lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/
class Solution
{
      public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		vector<int> pPath;
		createPath(root, p->val, pPath);
		vector<int> qPath;
		createPath(root, q->val, qPath);

		int best = root->val;
		for (size_t i = 0; i < min(pPath.size(), qPath.size()); ++i)
		{
			if (pPath[i] != qPath[i])
				break;
			best = pPath[i];
		}
		TreeNode* bestNode = descendTree(root, best);
		return bestNode ? bestNode : root;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::lowestCommonAncestor);
}
#endif