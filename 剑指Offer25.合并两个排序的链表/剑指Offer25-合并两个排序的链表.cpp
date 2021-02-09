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
    //1���ݹ鷨
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     if(l1 == nullptr || l2 == nullptr)
    //         return l1 ? l1 : l2;
    //     if(l1->val <= l2->val) {
    //         l1->next = mergeTwoLists(l1->next,l2);
    //         return l1;
    //     }
    //     else {
    //         l2->next = mergeTwoLists(l1,l2->next);
    //         return l2;
    //     }     
    // }

    //2��������������һ���µ�head���-1������l1,l2�ĺϲ���
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* pre = head;                 
        while(l1 != nullptr && l2 != nullptr)           //l1 l2 ˫ָ���ƶ�
        {
            if(l1->val <= l2->val)                      
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
        pre->next = l1 ? l1 : l2;
        return head->next;
    }
};