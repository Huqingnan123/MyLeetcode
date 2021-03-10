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
    int result = INT_MIN;
    // dfs + 递归
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return result;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) 
            return 0;

        // 递归计算左右子节点的最大贡献值(大于0才选择经过)
        int leftGain = max(dfs(root->left), 0);
        int rightGain = max(dfs(root->right), 0);

        // 自下而上地更新答案result
        result = max(result, root->val + leftGain + rightGain);

        // 返回节点的最大贡献值(对于再往上一层，leftGain和rightGain只能取到max的一边)
        return root->val + max(leftGain, rightGain);
    }

};