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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = l1;
        while(l1 || l2)
        {
            if(l1 && l2)
            {
                if(l2->next && !l1->next)       //l2���滹�ж�l1�޾�Ҫnew 0
                    l1->next = new ListNode(0);
                if(l1->val + l2->val >= 10)
                {
                    l1->val = (l1->val + l2->val) % 10;
                    if(l1->next)
                        l1->next->val += 1;
                    else
                        l1->next = new ListNode(1);
                }
                else
                    l1->val = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
                continue;
            }
            else
            {
                if(l1->val >= 10)     //ֻʣ��l1��Ԫ���ˣ�ֻ��Ҫ�ж��Ƿ���10
                {
                    l1->val = (l1->val) % 10;
                    if(l1->next)
                        l1->next->val += 1;
                    else
                        l1->next = new ListNode(1);
                    l1 = l1->next;
                    continue;
                }
                else
                    break;         //��ǰ����λ���涼����λ
            }  
        } 
        return root;      
    }
};