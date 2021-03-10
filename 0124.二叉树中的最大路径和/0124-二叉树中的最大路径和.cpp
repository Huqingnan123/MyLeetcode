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
    // dfs + �ݹ�
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return result;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) 
            return 0;

        // �ݹ���������ӽڵ�������ֵ(����0��ѡ�񾭹�)
        int leftGain = max(dfs(root->left), 0);
        int rightGain = max(dfs(root->right), 0);

        // ���¶��ϵظ��´�result
        result = max(result, root->val + leftGain + rightGain);

        // ���ؽڵ�������ֵ(����������һ�㣬leftGain��rightGainֻ��ȡ��max��һ��)
        return root->val + max(leftGain, rightGain);
    }

};