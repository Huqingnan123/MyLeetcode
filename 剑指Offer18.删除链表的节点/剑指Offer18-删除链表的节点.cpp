/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr && cur->val != val)
        {
            pre = cur;
            cur = cur->next;
        }
        if(pre != nullptr)
            pre->next = cur->next;
        else
            head = cur->next;
        return head;
    }
};