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
    int find = 0;  //ȫ�ֱ���find���ڱ����������Ƿ����ҵ�����ֹdfs����ʱ��count==2�޸�result
    TreeNode* result;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return result;
    }
    //��ÿ��������count��count==2֮�����̼�סresult = root, find��Ǳ�Ϊ1
    int dfs(TreeNode* root,TreeNode* p, TreeNode* q){
        int count = 0;     //��ÿ�����count�Ƿ�����������p,q
        if(root == p || root == q)
            count++;
        if(root->left)
            count += dfs(root->left, p , q);
        if(root->right)
            count += dfs(root->right, p , q);
        if(find)
            return 0;      //��ֹdfs�����޸��Ѿ��ҵ����������result
        if(count == 2)
        {
            find = 1;
            result = root;
        }
        return count;
    }
};