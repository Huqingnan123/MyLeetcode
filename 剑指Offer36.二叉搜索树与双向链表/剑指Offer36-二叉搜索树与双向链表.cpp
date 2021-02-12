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
        //中序遍历完成后，head指向头结点，pre指向尾结点，构建双向循环链表
        head->left = pre;
        pre->right = head;
        return head;
    }
    void inorderTraverse(Node* root) {
        if(root->left)
            inorderTraverse(root->left);
        //把BST最左下的结点设为head
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