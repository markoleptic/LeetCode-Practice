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
	TreeNode *buildTreeDFS(vector<int>& inorder, vector<int>& postorder)
	{
		unordered_map<int, int> inorderMap;
		for (int i = 0; i < inorder.size(); ++i)
		{
			inorderMap[inorder[i]] = i;
		}

		TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
		stack<TreeNode *> nodeStack;
		nodeStack.push(root);

		for (int i = postorder.size() - 2; i >= 0; --i)
		{
			TreeNode *node = new TreeNode(postorder[i]);
			TreeNode *current = nodeStack.top();

			if (inorderMap[node->val] > inorderMap[current->val])
			{
				// Move to the right child
				cout << "New right value: " << node->val << endl;
				current->right = node;
			}
			else
			{
				cout << "Popping stack: ";
				// Move to the left child
				while (!nodeStack.empty() && inorderMap[node->val] < inorderMap[nodeStack.top()->val])
				{
					current = nodeStack.top();
					cout << current->val << " ";
					nodeStack.pop();
				}
				cout << endl;
				cout << "New left value: " << node->val << endl;
				current->left = node;
			}

			nodeStack.push(node);
		}
		return root;
	}

	TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder) { return buildTreeDFS(inorder, postorder); }
};

#ifdef LC_LOCAL
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	exec(&Solution::buildTree);
}
#endif