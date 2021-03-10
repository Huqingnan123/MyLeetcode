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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;                                 //增加的一个头结点
        ListNode* pre = &dummy;                      
        while(l1 != nullptr && l2 != nullptr)           //l1 l2 双指针移动
        {
            if(l1->val <= l2->val)                      //prev->next 赋为 l1->val 与 l2->val 的较小结点，对应l1 或 l2后移
            {
                pre->next = l1;
                pre = l1;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                pre = l2;
                l2 = l2->next;
            }
        }
        if(l1 == nullptr)
            pre->next = l2;
        else
            pre->next = l1;
        return dummy.next;
    }
};