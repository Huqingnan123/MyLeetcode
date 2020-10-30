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
        ListNode* pre_head = new ListNode(-1);          //���ӵ�һ��ͷ���,prev��pre_headһ��ʼ��ָ��-1���
        ListNode* prev = pre_head;                      
        while(l1 != nullptr && l2 != nullptr)           //l1 l2 ˫ָ���ƶ�
        {
            if(l1->val <= l2->val)                      //prev->next ��Ϊ l1->val �� l2->val �Ľ�С��㣬��Ӧl1 �� l2����
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