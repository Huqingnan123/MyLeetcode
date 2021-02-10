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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //A,B必须都非空才可能返回true
        if(A == nullptr || B == nullptr)
            return false;
        //先看是否可以从当前A树的根节点开始一直匹配到B子结构，如果不行再从A->left和A->right入手匹配
        return helper(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }

    //从根节点开始“完全匹配判断”递归函数
    bool helper(TreeNode* A, TreeNode* B) {
        // 如果 B 已经遍历完了，true
        if(B == nullptr)
            return true;
        // 如果 B 还有，但 A 遍历完了，那 B 剩下的就没法匹配了，false
        if(A == nullptr)
            return false;
        // 存在对应位置的结点值不相等，false
        if(A->val != B->val)
            return false;
        return helper(A->left,B->left) && helper(A->right,B->right);
    }
};
        