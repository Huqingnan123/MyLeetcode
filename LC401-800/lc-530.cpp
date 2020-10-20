#include <iostream>
#include <math.h>
#include <algorithm>
 //Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int minimum = INT_MAX;
    TreeNode* prev = nullptr;
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minimum;
    }
    //中序遍历就是一个有序序列!!!
    void inorder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        //保证执行min操作时，prev一定是中序序列中在当前root之前的那一个结点!!!
        if (prev != nullptr)
            minimum = std::min(minimum, root->val - prev->val);
        //向右子树遍历之前，更新prev为当前root，当前root一定作为右子树中序遍历首结点的prev
        prev = root;
        inorder(root->right);
    }
};