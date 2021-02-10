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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            //采用count进行每一层的计数（达到分层效果）
            vector<int> temp;
            int count = q.size();
            while(count-- != 0)
            {
                TreeNode* cur = q.front();
                if(cur->left != nullptr)
                    q.push(cur->left);
                if(cur->right != nullptr)
                    q.push(cur->right);
                temp.push_back(cur->val);
                q.pop();
            }
            //一层的结点pop完成，将此层的元素存储
            result.push_back(temp);
        }
        return result;
    }
};