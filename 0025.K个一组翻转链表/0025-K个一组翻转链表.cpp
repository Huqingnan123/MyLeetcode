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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) 
            return nullptr;
        ListNode *first = head;
        //头插法
        ListNode *newHead = new ListNode(-1);
        ListNode *pre = newHead;

        while (first != nullptr) {
            ListNode *next;
            ListNode *last = first;
            int i;
            //计算一组k个结点，对于[first, last]之间进行reverse
            for (i = 1; i <= k-1 && last->next != nullptr; i++) 
                last = last->next;
            //最后一组不满k个，不用反转
            if (i != k) {
                pre->next = first;
                break;
            }
            //last->next赋值nullptr进行分割
            next = last->next;
            last->next = nullptr;
            pre->next = reverse(first);
            pre = first;
            first = next;
        }
        return newHead->next;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};