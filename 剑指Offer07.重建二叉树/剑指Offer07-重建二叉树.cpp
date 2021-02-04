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
    int pre_first = 0;                  //全局变量，标志着前序遍历序列仍未使用的第一个元素
    unordered_map<int,int> in_map;      //通过inorder内各元素值映射到inorder位置信息
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int in_index = 0;
        for(auto& val : inorder)
            in_map[val] = in_index++;
        return reBuild(0, (int)inorder.size()-1, preorder, inorder); 
    }
    //in_left 和 in_right 为中序序列左右边界（左闭右闭）
    TreeNode* reBuild(int in_left, int in_right, vector<int>& preorder, vector<int>& inorder){
        // 如果这里没有节点构造二叉树了，就结束返回nullptr
        if (in_left > in_right)
            return nullptr;
        // 选择前序遍历 pre_first 位置的元素作为当前子树的根节点
        int root_val = preorder[pre_first++];
        TreeNode* root = new TreeNode(root_val);
        // 根据 root 所在位置在中序inorder中分成左右两棵子树（unordered_map哈希查找更快）
        int in_middle = in_map[root_val];
        // 构造左子树
        root->left = reBuild(in_left, in_middle - 1, preorder, inorder);
        // 构造右子树
        root->right = reBuild(in_middle + 1, in_right, preorder, inorder);
        return root;
    }
};