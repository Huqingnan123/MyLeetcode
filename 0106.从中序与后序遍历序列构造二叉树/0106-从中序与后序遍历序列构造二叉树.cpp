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
    int post_last;                      //ȫ�ֱ�������־�ź������postorder���һ��Ԫ��
    unordered_map<int,int> in_map;      //ͨ��Ԫ��ֵӳ�䵽inorderλ����Ϣ
    TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_last = (int)postorder.size()-1;
        int in_index = 0;
        for(auto& val : inorder)
        {
            in_map[val] = in_index++;
        }
        return helper(0,(int)inorder.size()-1,inorder,postorder);  //�����������ұ߽磨����ұգ�
    }
    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder){
        // �������û�нڵ㹹��������ˣ��ͽ���
        if (in_left > in_right) {
            return nullptr;
        }

        // ѡ�� post_last λ�õ�Ԫ����Ϊ��ǰ�������ڵ�
        int root_val = postorder[post_last--];
        TreeNode* root = new TreeNode(root_val);

        // ���� root ����λ��������inorder�зֳ���������������unordered_map��ϣ���Ҹ��죩
        int in_middle = in_map[root_val];

        // ����һ�� �����Һ��� ��˳��
        // ����������
        root->right = helper(in_middle + 1, in_right, inorder, postorder);
        // ����������
        root->left = helper(in_left, in_middle - 1, inorder, postorder);
        return root;
    }
};