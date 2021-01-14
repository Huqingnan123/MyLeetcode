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
        //�����������в����Ƿ���� p ���� q
        //��� p �� q �ֱ������������У�left��right���ǿգ���ô��˵�����ڵ������͹������ȡ�
        //left��right��һ��Ϊ�գ�һ����Ϊ�գ���ֱ�ӷ��ز�Ϊ�յ���һ����
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr)
            return root;
        else
            return left ? left : right;
    }
};