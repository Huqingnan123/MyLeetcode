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
    int pre_first = 0;                  //ȫ�ֱ�������־��ǰ�����������δʹ�õĵ�һ��Ԫ��
    unordered_map<int,int> in_map;      //ͨ��inorder�ڸ�Ԫ��ֵӳ�䵽inorderλ����Ϣ
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int in_index = 0;
        for(auto& val : inorder)
            in_map[val] = in_index++;
        return reBuild(0, (int)inorder.size()-1, preorder, inorder); 
    }
    //in_left �� in_right Ϊ�����������ұ߽磨����ұգ�
    TreeNode* reBuild(int in_left, int in_right, vector<int>& preorder, vector<int>& inorder){
        // �������û�нڵ㹹��������ˣ��ͽ�������nullptr
        if (in_left > in_right)
            return nullptr;
        // ѡ��ǰ����� pre_first λ�õ�Ԫ����Ϊ��ǰ�����ĸ��ڵ�
        int root_val = preorder[pre_first++];
        TreeNode* root = new TreeNode(root_val);
        // ���� root ����λ��������inorder�зֳ���������������unordered_map��ϣ���Ҹ��죩
        int in_middle = in_map[root_val];
        // ����������
        root->left = reBuild(in_left, in_middle - 1, preorder, inorder);
        // ����������
        root->right = reBuild(in_middle + 1, in_right, preorder, inorder);
        return root;
    }
};