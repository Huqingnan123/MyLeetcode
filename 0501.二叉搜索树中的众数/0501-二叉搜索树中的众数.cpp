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
    vector<int> res;
    int base = 0, count = 0, maxNum = 0;
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr)
            return res;
        inorderTraverse(root);
        return res;
    }
    
    //inorder过程中update众数列表
    void update(int val) {
        if(val == base) {
            count++;
        }
        else {
            base = val;
            count = 1;
        }
        if(count == maxNum) {
            res.push_back(val);
        }
        else if(count > maxNum) {
            maxNum = count;
            res = vector<int> {base};
        }
    }

    void inorderTraverse(TreeNode* root) {  
        if(root == nullptr)
            return ;    
        inorderTraverse(root->left);
        update(root->val);
        inorderTraverse(root->right);
    }
};