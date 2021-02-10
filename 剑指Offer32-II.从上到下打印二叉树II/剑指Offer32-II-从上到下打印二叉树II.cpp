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
            //����count����ÿһ��ļ������ﵽ�ֲ�Ч����
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
            //һ��Ľ��pop��ɣ����˲��Ԫ�ش洢
            result.push_back(temp);
        }
        return result;
    }
};