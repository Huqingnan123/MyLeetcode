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
        int level = 1;
        while(!q.empty())
        {
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
            //通过level来判断是否需要reverse这一行
            if(level % 2 == 0)
                reverse(temp.begin(), temp.end());
            result.push_back(temp);
            level++;
        }
        return result;
    }
};