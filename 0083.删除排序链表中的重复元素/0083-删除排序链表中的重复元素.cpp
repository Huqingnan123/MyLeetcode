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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* cur = head;
        ListNode* nxt = head->next;
        while(cur != nullptr) {
            while(nxt != nullptr && cur->val == nxt->val) {
                nxt = nxt->next;
            }
            cur->next = nxt;
            cur = nxt;
            if(cur != nullptr)
                nxt = cur->next;
        }
        return head;
    }
};