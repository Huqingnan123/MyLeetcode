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
    int number = 0;
    vector<int> inorder_travel_result;
    vector<int> result;
    vector<int> findMode(TreeNode* root) {
        if(root)
        {
            inorder_travel(root);
        }
        int max_number = 0;
        int current_number = 0; 
        int pre_value;
        if(inorder_travel_result.size())
        {
            pre_value = inorder_travel_result[0];
            for(auto value : inorder_travel_result)
            {
                if(value == pre_value)
                {
                    current_number++;
                }
                else
                {
                    if(current_number == max_number)
                        result.emplace_back(pre_value);
                    else if(current_number > max_number)
                    {
                        result = vector<int>(1,pre_value);
                        max_number = current_number;  //此时current_number相当于最新众数的出现次数
                    }
                    pre_value = value;
                    current_number = 1;    //当前value---第一次遇到的一个数
                } 
            }
            if(current_number == max_number)   //循环结束后对最后的current做判断是否需要更新众数
                result.emplace_back(pre_value);
            else if(current_number > max_number)
            {
                result = vector<int>(1,pre_value);
            }
        }    
        return result;
    }
    void inorder_travel(TreeNode* root){      //inorder_travel自动""针对BST""形成升序vector
        if(root->left)
            inorder_travel(root->left);
        inorder_travel_result.emplace_back(root->val);
        if(root->right)
            inorder_travel(root->right);
    }
};