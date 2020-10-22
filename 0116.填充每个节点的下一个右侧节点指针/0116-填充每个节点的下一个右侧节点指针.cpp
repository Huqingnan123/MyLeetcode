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
        if (root)
        {
            queue<Node*> node_queue;
            node_queue.push(root);
            while (!node_queue.empty()) 
            {
                auto n = node_queue.size(); //此时可以得到当前层的节点个数
                for (int i = 0; i < n; i++) //一个for循环把当前层都出队列。下一层的所有孩子都入队列
                {
                    Node* peek = node_queue.front();
                    node_queue.pop();
                    //i+1 == n 表示到达每一层最后一个节点，next为nullptr
                    peek->next = ((i + 1) == n ? nullptr : node_queue.front());
                    if (peek->left) 
                        node_queue.push(peek->left);
                    if (peek->right) 
                        node_queue.push(peek->right);
                }
            }
        }
        return root;
    }
};