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
    // 1¡¢µü´ú·¨
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* pre = nullptr;
    //     ListNode* cur = head;
    //     while(cur != nullptr) {
    //         ListNode* nxt = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = nxt;
    //     }
    //     return pre;
    // }

    // 2¡¢µÝ¹é·¨
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};