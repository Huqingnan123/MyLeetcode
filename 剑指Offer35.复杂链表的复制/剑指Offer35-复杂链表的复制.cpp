/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        Node* cur = head;
        //在每个节点后面复制一个一模一样的新节点
        //比如 1->2->3 会成为 1->1->2->2->3->3
        while(cur != nullptr)
        {
            Node* clone = new Node(cur->val);
            clone->next = cur->next;
            cur->next = clone;
            cur = clone->next;
        }
        //建立相同的random链接
        cur = head;
        while(cur != nullptr)
        {
            Node* clone = cur->next;
            if(cur->random != nullptr)
                clone->random = cur->random->next;
            cur = clone->next;
        }
        //拆分出新复制的复杂链表(两条一样的复杂链表)
        cur = head;
        Node* cloneHead = head->next;
        while(cur != nullptr)
        {
            Node* clone = cur->next;
            cur->next = clone->next;
            if(cur->next != nullptr)
                clone->next = cur->next->next;
            cur = cur->next;
        }
        return cloneHead;
    }
};