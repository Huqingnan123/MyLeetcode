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
    ListNode* partition(ListNode* head, int x) {
        //add an addtional Node(-1)
        ListNode* addNode = new ListNode(-1);
        addNode->next = head;
        ListNode* prev1 = addNode;
        ListNode* bigger = head;
        //find a bigger node than x
        while(bigger != nullptr && bigger->val < x)
        {
            prev1 = bigger;
            bigger = bigger->next;
        }
        if(bigger == nullptr)
            return head;
        ListNode* smaller = bigger->next;
        ListNode* prev2 = bigger;
        //only change the ptr direction of smaller node than x 
        while(smaller != nullptr)
        {
            if(smaller->val >= x)
            {
                prev2 = smaller;
                smaller = smaller->next;
                continue;
            }
            else
            {
                prev1->next = smaller;
                prev2->next = smaller->next;
                smaller = smaller->next;
                prev1->next->next = bigger;
                prev1 = prev1->next;
            }
        }
        return addNode->next;
    }
};