// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int full = 0;
        ListNode* head = new ListNode(0);
        ListNode* L_add = head;
        while (l1 != nullptr && l2 != nullptr)
        {
            int add = L_add->val + l1->val + l2->val;
            L_add->val = add % 10;
            if (add >= 10)
                full = 1;
            L_add->next = full == 0 ? new ListNode(0) : new ListNode(1);
            l1 = l1->next;
            l2 = l2->next;
            if (l1 == nullptr && l2 == nullptr && L_add->next->val == 0)
            {
                L_add->next = nullptr;
                return head;
            }
            if (l1 == nullptr && l2 == nullptr && L_add->next->val == 1)
                return head;
            L_add = L_add->next;
            full = 0;      //进位的标志
        }
        if (l1 == nullptr)
        {
            while (l2 != nullptr)
            {
                L_add->val += l2->val;
                if (L_add->val < 10)
                {
                    L_add->next = l2->next;
                    return head;
                }
                if (L_add->val >= 10)
                {
                    L_add->val = L_add->val % 10;
                    L_add->next = new ListNode(1);
                    L_add = L_add->next;
                    l2 = l2->next;
                }
            }
        }
        if (l2 == nullptr)
        {
            while (l1 != nullptr)
            {
                L_add->val += l1->val;
                if (L_add->val < 10)
                {
                    L_add->next = l1->next;
                    return head;
                }
                if (L_add->val >= 10)
                {
                    L_add->val = L_add->val % 10;
                    L_add->next = new ListNode(1);
                    L_add = L_add->next;
                    l1 = l1->next;
                }
            }
        }
        return head;
    }
};
