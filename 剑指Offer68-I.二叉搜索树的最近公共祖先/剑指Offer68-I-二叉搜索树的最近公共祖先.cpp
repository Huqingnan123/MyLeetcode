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
    //¶þ²æËÑË÷Ê÷£º root->val >= p->val && root->val <= q->val 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        //go to left branch
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        //go to right branch
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        //this root is the lowestCommonAncestor  
        return root;
    }
};