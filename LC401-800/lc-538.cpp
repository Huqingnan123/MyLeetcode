struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {  //���ұ����еķ����������  ��ÿһ����������->��->��
        if (root)
        {
            convertBST(root->right);
            sum += root->val;              //sumһֱ�Ǳ�root->val������н��֮��
            root->val = sum;               //���µ�ǰ��root->val
            convertBST(root->left);        
        }
        return root;
    }
};