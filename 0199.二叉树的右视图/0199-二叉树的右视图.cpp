/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int count = q.size();
            // 右视图（如果优先push左孩子，每一层的last one才进入result）
            while(count-- != 0) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                // last one
                if(count == 0)
                    result.push_back(temp->val);
            }
        }
        return result;
    } 
};