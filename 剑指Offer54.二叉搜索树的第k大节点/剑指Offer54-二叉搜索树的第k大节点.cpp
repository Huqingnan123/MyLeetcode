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
    // 1、根据右->中->左的反中序顺序（递减顺序）遍历，计数至第k个即可
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

    // 2、正常的左->中->右的中序遍历，存储进vector中，直接取vec.size()-k索引处的值
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