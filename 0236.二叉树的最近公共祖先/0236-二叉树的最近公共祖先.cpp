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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) 
            return root;    
        //在左右两边找是否存在p,q的祖先节点，如果分居两边，说明当前root就是公共祖先节点，否则p,q居于一侧
        TreeNode* left =  lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);      
        if(left == nullptr)
            return right;
        if(right == nullptr)
            return left;      
        return root;
    }
};