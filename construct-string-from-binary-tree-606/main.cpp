#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/*
Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.
*/
class Solution
{
      public:
	void pre_order(TreeNode *node, string &out)
	{
		if (!node)
			return;
		out.insert(out.size(), std::to_string(node->val));

		if (node->left)
		{
			out.insert(out.size(), "(");
			pre_order(node->left, out);
			out.insert(out.size(), ")");
		}
		if (node->right)
		{
			if (!node->left)
			{
				out.insert(out.size(), "()");
			}
			out.insert(out.size(), "(");
			pre_order(node->right, out);
			out.insert(out.size(), ")");
		}
	}

      public:
	string tree2str(TreeNode *root)
	{
		string Out = "";
		TreeNode *current = root;
		pre_order(current, Out);
		return Out;
	}
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::tree2str);
}
#endif