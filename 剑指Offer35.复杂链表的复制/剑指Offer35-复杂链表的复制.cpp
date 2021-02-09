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
        //��ÿ���ڵ���渴��һ��һģһ�����½ڵ�
        //���� 1->2->3 ���Ϊ 1->1->2->2->3->3
        while(cur != nullptr)
        {
            Node* clone = new Node(cur->val);
            clone->next = cur->next;
            cur->next = clone;
            cur = clone->next;
        }
        //������ͬ��random����
        cur = head;
        while(cur != nullptr)
        {
            Node* clone = cur->next;
            if(cur->random != nullptr)
                clone->random = cur->random->next;
            cur = clone->next;
        }
        //��ֳ��¸��Ƶĸ�������(����һ���ĸ�������)
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