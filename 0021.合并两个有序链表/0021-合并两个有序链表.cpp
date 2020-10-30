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
        ListNode* pre_head = new ListNode(-1);          //增加的一个头结点,prev和pre_head一开始都指向-1结点
        ListNode* prev = pre_head;                      
        while(l1 != nullptr && l2 != nullptr)           //l1 l2 双指针移动
        {
            if(l1->val <= l2->val)                      //prev->next 赋为 l1->val 与 l2->val 的较小结点，对应l1 或 l2后移
            {
                prev->next = l1;
                prev = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;
                prev = l2;
                l2 = l2->next;
            }
        }
        if(l1 == nullptr)
            prev->next = l2;
        else
            prev->next = l1;
        return pre_head->next;
    }
};