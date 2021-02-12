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
    // 1��������->��->��ķ�����˳�򣨵ݼ�˳�򣩱�������������k������
    // int count = 0;
    // int result;
    // int kthLargest(TreeNode* root, int k) {
    //     inorderTraverse(root, k);
    //     return result;
    // }
    // void inorderTraverse(TreeNode* root, int k) {
    //     if(root->right)
    //         inorderTraverse(root->right, k);
    //     count++;
    //     if(count == k)
    //     {
    //         result = root->val;
    //         return;
    //     }
    //     if(root->left)
    //         inorderTraverse(root->left, k);
    // }

    // 2����������->��->�ҵ�����������洢��vector�У�ֱ��ȡvec.size()-k��������ֵ
    vector<int> vec; 
    int kthLargest(TreeNode* root, int k) {
        inorderTraverse(root);
        return vec[vec.size()-k];
    }
    void inorderTraverse(TreeNode* root) {
        if(root->left)
            inorderTraverse(root->left);
        vec.push_back(root->val);
        if(root->right)
            inorderTraverse(root->right);
    }
};