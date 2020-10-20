#include <iostream>
// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
	{
		if (t1 && t2)
			t1->val += t2->val;
		else if (!t1 && t2)
		{
			t1 = new TreeNode(t2->val);
		}
		else
		{
			return nullptr;
		}
		mergeTrees(t1->left, t2->left);
		mergeTrees(t1->right, t2->right);
		return t1;
	}
};
