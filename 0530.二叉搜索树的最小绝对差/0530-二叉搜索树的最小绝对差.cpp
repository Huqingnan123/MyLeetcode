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
    int result = INT_MAX;
    int pre = -1;
    int getMinimumDifference(TreeNode* root) {
        inorderTraverse(root);
        return result;
    }
    void inorderTraverse(TreeNode* root) {
        if(root == nullptr) 
            return ;
        inorderTraverse(root->left);
        if(pre != -1)
            result = min(result, root->val - pre);
        pre = root->val;
        inorderTraverse(root->right);
    }
};