/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool AllBalanced = true;
    bool isBalanced(TreeNode* root) {
        maxdepth(root);
        return AllBalanced;
    }
    int maxdepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int leftDepth = maxdepth(root->left);
        int rightDepth = maxdepth(root->right);
        if(abs(leftDepth - rightDepth) > 1)
            AllBalanced = false;
        return max(leftDepth,rightDepth) + 1;
    }
};