#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

// 0 if less than
// 1 if greater than
int traverseTree(TreeNode* node, TreeNode* &previous)
{
    if (!node) 
        return 0;
    
    if (traverseTree(node->left, previous) != 0)
        return -1;

	if (previous != nullptr && previous->val >= node->val) 
		return -1;

	previous = node;

    return traverseTree(node->right, previous);
}

/**
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

	The leftsubtree of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than the node's key.
	Both the left and right subtrees must also be binary search trees.

*/
class Solution
{
public:
	bool isValidBST(TreeNode *root) {
		TreeNode* prev = nullptr;
		return traverseTree(root, prev) == 0;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::isValidBST);
}
#endif