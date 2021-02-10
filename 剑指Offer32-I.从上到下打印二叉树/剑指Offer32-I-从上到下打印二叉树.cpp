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
    vector<int> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            if(cur->left != nullptr)
                q.push(cur->left);
            if(cur->right != nullptr)
                q.push(cur->right);
            result.push_back(cur->val);
            q.pop();
        }
        return result;
    }
};