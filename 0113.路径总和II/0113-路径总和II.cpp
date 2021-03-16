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
    vector<vector<int>> result;
    vector<int> temp;
    int current_sum = 0;      //�����п������Σ���������temp��current_sum
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        helper(root,sum);   //helper�ݹ飬��������result
        return result;
    }

    void helper(TreeNode* root, int sum){
        if(root == nullptr)
            return ;
        temp.push_back(root->val);
        current_sum += root->val;
        //����Ҷ�ӽ�㲢���ܺ͵���sum���洢temp
        if(root->left == nullptr && root->right == nullptr && current_sum == sum)   
            result.push_back(temp);
        else {          
            helper(root->left, sum);
            helper(root->right, sum);
        }
        temp.pop_back();         //�����ݹ鷵����һ��ʱ��pop����ǰβԪ�أ�current_sum���»�ȥ
        current_sum -= root->val;
    }
};