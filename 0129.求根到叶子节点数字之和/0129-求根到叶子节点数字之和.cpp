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
    int all_sum = 0;
    int sumNumbers(TreeNode* root) {
        if(root)
            helper(root,0);                  //singlePath_sum��ʾ��ǰһ����->Ҷ��·���ϵ��ܺ�
        return all_sum;
    }
    void helper(TreeNode* root,int singlePath_sum){
        singlePath_sum = singlePath_sum*10 + root->val;
        if(root->left)
            helper(root->left,singlePath_sum);
        if(root->right)
            helper(root->right,singlePath_sum);
        if(root->left == nullptr && root->right == nullptr)
            all_sum += singlePath_sum;           //����Ҷ�ӽ��֮���ٰ��ܺ��ۼӵ�all_sum��   
    }
};