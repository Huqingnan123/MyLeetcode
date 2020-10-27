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
    //递归很简单，可以用迭代方法实现
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
                result.push_back(temp->val);         //先把当前根结点val保存在result
                if(temp->right)
                    node_stack.push(temp->right);    //栈是后入先出，故先入right后入left
                if(temp->left)
                    node_stack.push(temp->left);
            }
        }
        return result;
    }
};