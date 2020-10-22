/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {  
        if(root)
        {
            queue<Node*> node_ptr;
            Node* temp;
            node_ptr.push(root);
            node_ptr.push(nullptr);
            while(!node_ptr.empty())
            {
                temp = node_ptr.front();
                node_ptr.pop();
                if(temp == nullptr && !node_ptr.empty())
                    node_ptr.push(nullptr);
                else if(temp)
                {
                    temp->next = node_ptr.front();
                    if(temp->left)
                        node_ptr.push(temp->left);
                    if(temp->right)
                        node_ptr.push(temp->right);
                }
            }
        }
        return root;
    }
};