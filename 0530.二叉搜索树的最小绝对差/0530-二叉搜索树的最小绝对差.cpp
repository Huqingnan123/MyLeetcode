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
    int minimum = INT_MAX;
    TreeNode* prev = nullptr;
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minimum;
    }
    //�����������һ����������!!!
    void inorder(TreeNode* root)
    {
        if(root == nullptr) 
            return;
        inorder(root -> left);     
        //��ִ֤��min����ʱ��prevһ���������������ڵ�ǰroot֮ǰ����һ�����
        if(prev != nullptr) 
            minimum = min(minimum, root -> val - prev -> val);
        //������������֮ǰ������prevΪ��ǰroot
        prev = root;          
        inorder(root -> right);
    }
};