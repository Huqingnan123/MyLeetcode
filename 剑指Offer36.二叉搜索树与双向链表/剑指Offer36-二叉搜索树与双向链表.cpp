/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* head = nullptr;
    Node* pre = nullptr;
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        inorderTraverse(root);
        //���������ɺ�headָ��ͷ��㣬preָ��β��㣬����˫��ѭ������
        head->left = pre;
        pre->right = head;
        return head;
    }
    void inorderTraverse(Node* root) {
        if(root->left)
            inorderTraverse(root->left);
        //��BST�����µĽ����Ϊhead
        if(head == nullptr)
            head = root;
        if(pre != nullptr)
        {
            pre->right = root;
            root->left = pre;
        }
        pre = root;
        if(root->right)
            inorderTraverse(root->right);
    }
};