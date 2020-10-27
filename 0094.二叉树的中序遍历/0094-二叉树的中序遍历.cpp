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
    //递归算法很简单，采用栈模拟迭代的方法实现
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node_stack;
        TreeNode* cur = root;
        while (cur != nullptr || !node_stack.empty()) {
            if (cur != nullptr) {               // 指针来访问节点，访问到最底层
                node_stack.push(cur);           // 将访问的节点放进栈
                cur = cur->left;                // 一直往左，直到空结点
            } 
            else {                              //当cur == nullptr的时候，需要弹栈
                cur = node_stack.top();         // 从栈里弹出的数据，就是要放进result数组里的数据）
                node_stack.pop();
                result.push_back(cur->val);     // 当前子树的根节点处理
                cur = cur->right;               // 当前子树根节点的右子树进行相同处理
            }
        }
        return result;
    }
};