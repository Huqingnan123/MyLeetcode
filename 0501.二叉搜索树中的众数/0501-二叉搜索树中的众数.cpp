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
                        max_number = current_number;  //��ʱcurrent_number�൱�����������ĳ��ִ���
                    }
                    pre_value = value;
                    current_number = 1;    //��ǰvalue---��һ��������һ����
                } 
            }
            if(current_number == max_number)   //ѭ�������������current���ж��Ƿ���Ҫ��������
                result.emplace_back(pre_value);
            else if(current_number > max_number)
            {
                result = vector<int>(1,pre_value);
            }
        }    
        return result;
    }
    void inorder_travel(TreeNode* root){      //inorder_travel�Զ�""���BST""�γ�����vector
        if(root->left)
            inorder_travel(root->left);
        inorder_travel_result.emplace_back(root->val);
        if(root->right)
            inorder_travel(root->right);
    }
};