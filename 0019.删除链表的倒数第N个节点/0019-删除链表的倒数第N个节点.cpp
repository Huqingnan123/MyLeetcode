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
        if(prev == nullptr)              //表示要删除第一个节点，left指向第一个
            head = left->next;
        else                             //表示要删除后面的节点（prev非空）
            prev->next = left->next;
        return head;
    }
};