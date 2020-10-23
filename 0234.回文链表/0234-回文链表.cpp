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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return 1;
        ListNode* slow = head;
        ListNode* fast = head;
        //用slow指向中间结点，奇数正中间，偶数偏左
        //注意while的循环判断条件 fast->next && fast->next->next 才移动 fast
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* L1 = head;
        ListNode* L2 = slow->next;     //L1和L2是链表从中间断开形成的两个子链表
        ListNode* pre = nullptr;       
        ListNode* save_next = nullptr; //用于翻转L2链表
        while(L2 != nullptr)
        {
            save_next = L2->next;
            L2->next = pre;
            pre = L2;
            L2 = save_next;
        }
        L2 = pre;                      //反转之后，L2就是反转之后的链表头
        while(L2 != nullptr)           //现在进行L1和L2的顺序比较即可(只需走完L2即可)
        {
            if(L1->val != L2->val)
                return 0;
            L1 = L1->next;
            L2 = L2->next;
        }
        return 1;
    }
};