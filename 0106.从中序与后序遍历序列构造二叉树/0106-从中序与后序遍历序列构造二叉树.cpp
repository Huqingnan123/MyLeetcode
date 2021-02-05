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
    int post_last;                      //全局变量，标志着后序遍历postorder最后一个元素
    unordered_map<int,int> in_map;      //通过元素值映射到inorder位置信息
    TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_last = (int)postorder.size()-1;
        int in_index = 0;
        for(auto& val : inorder)
        {
            in_map[val] = in_index++;
        }
        return helper(0,(int)inorder.size()-1,inorder,postorder);  //中序序列左右边界（左闭右闭）
    }
    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder){
        // 如果这里没有节点构造二叉树了，就结束
        if (in_left > in_right) {
            return nullptr;
        }

        // 选择 post_last 位置的元素作为当前子树根节点
        int root_val = postorder[post_last--];
        TreeNode* root = new TreeNode(root_val);

        // 根据 root 所在位置在中序inorder中分成左右两棵子树（unordered_map哈希查找更快）
        int in_middle = in_map[root_val];

        // 这里一定 “先右后左” 的顺序
        // 构造右子树
        root->right = helper(in_middle + 1, in_right, inorder, postorder);
        // 构造左子树
        root->left = helper(in_left, in_middle - 1, inorder, postorder);
        return root;
    }
};