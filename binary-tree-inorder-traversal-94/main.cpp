#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/
class Solution
{
      public:

	void pre_order(TreeNode* node, vector<int>& out)
	{
		if (!node) return;
		out.push_back(node->val);
		if (node->left)
		{
			pre_order(node, out);
		}
		if (node->right)
		{
			pre_order(node, out);
		}
	}

	void in_order(TreeNode *node, vector<int> &out)
	{
		if (!node)
			return;
		if (node->left)
		{
			in_order(node->left, out);
		}
		out.push_back(node->val);
		if (node->right)
		{
			in_order(node->right, out);
		}
	}

      public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> out;
		in_order(root, out);
		return out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::inorderTraversal); // CHANGE FOR PROBLEM
}
#endif