/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    int result = 0;
    int kthSmallest(TreeNode* root, int k) {
        inorderTraverse(root, k);
        return result;
    }
    void inorderTraverse(TreeNode* root, int k) {
        if(root == nullptr)
            return ;
        inorderTraverse(root->left, k);
        count++;
        if(count == k)
            result = root->val;
        inorderTraverse(root->right, k);
    }
};