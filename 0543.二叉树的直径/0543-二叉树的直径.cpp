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
    int result = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        TreeDepth(root);
        return result;
    }
    int TreeDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int lDepth = TreeDepth(root->left);
        int rDepth = TreeDepth(root->right);
        result = max(lDepth + rDepth, result);
        return max(lDepth, rDepth) + 1;
    }
};