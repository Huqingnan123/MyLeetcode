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
        ListNode dummy;                                 //���ӵ�һ��ͷ���
        ListNode* pre = &dummy;                      
        while(l1 != nullptr && l2 != nullptr)           //l1 l2 ˫ָ���ƶ�
        {
            if(l1->val <= l2->val)                      //prev->next ��Ϊ l1->val �� l2->val �Ľ�С��㣬��Ӧl1 �� l2����
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