#ifdef LC_LOCAL
#include "../parser.hpp"
#else
#define dbg(...)
#endif

/**
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is
the inorder traversal of the same tree, construct and return the binary tree.
*/
class Solution
{
public:
	TreeNode *buildTreeDFS(vector<int> &preorder, vector<int> &inorder)
	{
		unordered_map<int, int> inorderMap;
		for (int i = 0; i < inorder.size(); ++i)
		{
			inorderMap[inorder[i]] = i;
		}

		TreeNode *root = new TreeNode(preorder[0]);
		stack<TreeNode *> nodeStack;
		nodeStack.push(root);

		for (int i = 1; i < preorder.size(); ++i)
		{
			TreeNode *node = new TreeNode(preorder[i]);
			TreeNode *current = nodeStack.top();

			if (inorderMap[node->val] < inorderMap[current->val])
			{
				// Move to the left child
				cout << "New left value: " << node->val << endl;
				current->left = node;
			}
			else
			{
				cout << "Popping stack: ";
				// Move to the right child
				while (!nodeStack.empty() && inorderMap[node->val] > inorderMap[nodeStack.top()->val])
				{
					current = nodeStack.top();
					cout << current->val << " ";
					nodeStack.pop();
				}
				cout << endl;
				cout << "New right value: " << node->val << endl;
				current->right = node;
			}

			nodeStack.push(node);
		}
		return root;
	}

	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) { return buildTreeDFS(preorder, inorder); }
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::buildTree);
}
#endif