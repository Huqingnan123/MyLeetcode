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
    //�ݹ�ܼ򵥣������õ�������ʵ��
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node_stack;
        TreeNode* temp;
        node_stack.push(root);
        while(!node_stack.empty())
        {
            temp = node_stack.top();
            node_stack.pop();
            if(temp != nullptr)
            {
                result.push_back(temp->val);         //�Ȱѵ�ǰ�����val������result
                if(temp->right)
                    node_stack.push(temp->right);    //ջ�Ǻ����ȳ���������right����left
                if(temp->left)
                    node_stack.push(temp->left);
            }
        }
        return result;
    }
};