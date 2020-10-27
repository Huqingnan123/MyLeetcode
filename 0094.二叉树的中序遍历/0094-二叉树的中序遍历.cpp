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
    //�ݹ��㷨�ܼ򵥣�����ջģ������ķ���ʵ��
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node_stack;
        TreeNode* cur = root;
        while (cur != nullptr || !node_stack.empty()) {
            if (cur != nullptr) {               // ָ�������ʽڵ㣬���ʵ���ײ�
                node_stack.push(cur);           // �����ʵĽڵ�Ž�ջ
                cur = cur->left;                // һֱ����ֱ���ս��
            } 
            else {                              //��cur == nullptr��ʱ����Ҫ��ջ
                cur = node_stack.top();         // ��ջ�ﵯ�������ݣ�����Ҫ�Ž�result����������ݣ�
                node_stack.pop();
                result.push_back(cur->val);     // ��ǰ�����ĸ��ڵ㴦��
                cur = cur->right;               // ��ǰ�������ڵ��������������ͬ����
            }
        }
        return result;
    }
};