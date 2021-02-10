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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return judgeSymmetric(root->left, root->right);
    }
    bool judgeSymmetric(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr && t2 == nullptr)
            return true;
        if(t1 == nullptr || t2 == nullptr)
            return false;
        if(t1->val != t2->val)
            return false;
        //镜像对称进行比较
        return judgeSymmetric(t1->left, t2->right) && judgeSymmetric(t1->right, t2->left);
    }
};