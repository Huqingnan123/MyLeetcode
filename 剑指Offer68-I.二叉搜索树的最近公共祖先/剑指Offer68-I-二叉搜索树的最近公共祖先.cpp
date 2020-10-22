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
    int find = 0;  //全局变量find用于标记最近祖先是否已找到，阻止dfs回溯时因count==2修改result
    TreeNode* result;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return result;
    }
    //对每个结点计数count，count==2之后立刻记住result = root, find标记变为1
    int dfs(TreeNode* root,TreeNode* p, TreeNode* q){
        int count = 0;     //对每个结点count是否子树包含了p,q
        if(root == p || root == q)
            count++;
        if(root->left)
            count += dfs(root->left, p , q);
        if(root->right)
            count += dfs(root->right, p , q);
        if(find)
            return 0;      //防止dfs回溯修改已经找到的最近祖先result
        if(count == 2)
        {
            find = 1;
            result = root;
        }
        return count;
    }
};