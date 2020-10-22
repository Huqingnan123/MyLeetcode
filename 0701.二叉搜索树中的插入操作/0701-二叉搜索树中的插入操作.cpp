/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
        {
            root = new TreeNode(val);
        }
        else
        {
            pair<TreeNode*,bool> father = make_pair(root,0);   //0 is left
            TreeNode* temp = root;
            while(temp != nullptr)
            {
                father.first = temp;
                if(val > temp->val)
                {
                    temp = temp->right;
                    father.second = 1;
                }
                else
                {
                    temp = temp->left;
                    father.second = 0;
                }
            }
            if(father.second == 1)
                father.first->right = new TreeNode(val);
            else
                father.first->left = new TreeNode(val);
        }
        return root;
    }
};