struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {  //“右边先行的反中序遍历”  对每一棵子树：右->中->左
        if (root)
        {
            convertBST(root->right);
            sum += root->val;              //sum一直是比root->val大的所有结点之和
            root->val = sum;               //更新当前的root->val
            convertBST(root->left);        
        }
        return root;
    }
};