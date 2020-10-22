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
    //t1Ϊ�յĵط�ֱ�ӷ���t2,t2Ϊ�յĵط�ֱ�ӷ���t1�����߶���Ϊ�ս�ֵ�����t1
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        // �Ⱥϲ����ڵ�
        t1->val += t2->val;            
        // �ٵݹ�ϲ���������
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};