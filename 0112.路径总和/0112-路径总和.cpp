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
    int curSum = 0;
    bool find = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return find;
    }
    void dfs(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return ;
        curSum += root->val;
        if(root->left == nullptr && root->right == nullptr && curSum == targetSum)
            find = true;
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        curSum -= root->val;
    }
};