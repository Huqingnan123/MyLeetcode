/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* right = head;
        ListNode* left = head;
        ListNode* prev = nullptr;
        for(int count = 0; count < n; count++)  //set double pointer left and right(dis = k)
            right = right->next;         
        while(right != nullptr)
        {
            prev = left;
            left = left->next;
            right = right->next;
        }
        if(prev == nullptr)              //��ʾҪɾ����һ���ڵ㣬leftָ���һ��
            head = left->next;
        else                             //��ʾҪɾ������Ľڵ㣨prev�ǿգ�
            prev->next = left->next;
        return head;
    }
};