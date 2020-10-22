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
                if(l2->next && !l1->next)       //l2后面还有而l1无就要new 0
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
                if(l1->val >= 10)     //只剩下l1有元素了，只需要判断是否满10
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
                    break;         //当前不进位后面都不进位
            }  
        } 
        return root;      
    }
};