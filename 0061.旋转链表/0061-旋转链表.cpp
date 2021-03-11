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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;
        ListNode *first = head, *last = head, *mid = head;
        int length = 1;
        while(last->next != nullptr) {
            length++;
            last = last->next;
        }
        int number = k % length;
        if(number == 0)
            return head;
        //相当于只需要把链表最后number个元素rotate移到前面即可
        for(int i = 0; i < length - number - 1; i++)
            mid = mid->next;
        ListNode* newHead = mid->next;
        last->next = first;
        mid->next = nullptr;
        return newHead;
    }
};