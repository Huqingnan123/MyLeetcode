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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != nullptr && fast != nullptr)
        {
            slow = slow->next;           //move 1
            if(fast->next == nullptr)    //fast->next会为空说明无环
                return nullptr;
            fast = fast->next->next;     //move 2

            //when they meet, find merge position, they must meet
            if(fast == slow)
            {
                while(head != fast)   //equal distance to merge point
                {
                    head = head->next;
                    fast = fast->next;
                }
                return head;          
            }
        }
        return nullptr;
    }
};