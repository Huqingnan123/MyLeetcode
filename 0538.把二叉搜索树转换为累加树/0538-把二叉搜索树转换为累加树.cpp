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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root)
        {
            convertBST(root->right);
            sum += root->val;              //sum一直是比root->val大的所有结点之和
            root->val = sum;               
            convertBST(root->left);
        }
        return root;
    }
};