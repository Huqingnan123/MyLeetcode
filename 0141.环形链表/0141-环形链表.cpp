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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != nullptr && fast != nullptr)
        {
            if(fast->next == nullptr)
                return false;
            slow = slow->next;
            fast = fast->next->next;
            // 链表有环，两指针一定会相遇
            if(fast == slow)
                return true;
        }
        return false;
    }
};