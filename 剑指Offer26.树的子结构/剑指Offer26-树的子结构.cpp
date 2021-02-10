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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //A,B���붼�ǿղſ��ܷ���true
        if(A == nullptr || B == nullptr)
            return false;
        //�ȿ��Ƿ���Դӵ�ǰA���ĸ��ڵ㿪ʼһֱƥ�䵽B�ӽṹ����������ٴ�A->left��A->right����ƥ��
        return helper(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    }

    //�Ӹ��ڵ㿪ʼ����ȫƥ���жϡ��ݹ麯��
    bool helper(TreeNode* A, TreeNode* B) {
        // ��� B �Ѿ��������ˣ�true
        if(B == nullptr)
            return true;
        // ��� B ���У��� A �������ˣ��� B ʣ�µľ�û��ƥ���ˣ�false
        if(A == nullptr)
            return false;
        // ���ڶ�Ӧλ�õĽ��ֵ����ȣ�false
        if(A->val != B->val)
            return false;
        return helper(A->left,B->left) && helper(A->right,B->right);
    }
};
        