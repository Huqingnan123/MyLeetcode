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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        int length = 1;
        ListNode* cur = head;
        while(cur->next != nullptr) {
            cur = cur->next;
            length++;
        }
        //开始归并排序
        return mergeSort(head, length);
    }

    ListNode* mergeSort(ListNode* head, int length) {
        if(length == 0 || length == 1)
            return head;
        ListNode *fast = head;
        ListNode* slow = head;
        ListNode* pre = head;
        int len1 = length / 2;
        int len2 = length - len1;
        //通过快慢指针找到中间结点slow
        while(fast != nullptr && fast->next != nullptr) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //链表从中间切断(head与slow是左右两个链表头结点)
        pre->next = nullptr;
        ListNode* head1 = mergeSort(head, len1);
        ListNode* head2 = mergeSort(slow, len2);
        return mergeTwo(head1, head2);
    }

    ListNode* mergeTwo(ListNode* head1, ListNode* head2) {
        //头插法
        ListNode dummy;
        ListNode* pre = &dummy;
        while(head1 != nullptr && head2 != nullptr) {
            if(head1->val <= head2->val) {
                pre->next = head1;
                pre = head1;
                head1 = head1->next;
            } 
            else {
                pre->next = head2;
                pre = head2;
                head2 = head2->next;
            }
        }
        if(head2 == nullptr) {
            pre->next = head1;
        }
        else {
            pre->next = head2;
        }
        return dummy.next;
    }
};