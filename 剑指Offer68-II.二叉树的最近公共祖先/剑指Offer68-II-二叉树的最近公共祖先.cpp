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
        //在左右子树中查找是否存在 p 或者 q
        //如果 p 和 q 分别在两个子树中，left和right都非空，那么就说明根节点就是最低公共祖先。
        //left和right中一个为空，一个不为空，就直接返回不为空的那一个。
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr)
            return root;
        else
            return left ? left : right;
    }
};