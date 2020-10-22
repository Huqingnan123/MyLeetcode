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
//找到原链表的中点（快慢指针）（距离k的指针则可以找到第个节点）

//将原链表的右半端反转（迭代法）

//将原链表的两端合并（间隔插入）
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;        //分成l1和l2两个链表
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    //slow为第n/2个节点指针（n为size-1)
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;   //save next node
            curr->next = prev;
            prev = curr;                       //update prev
            curr = nextTemp;                   //update curr
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;                 //save l1->next and l2->next

            l1->next = l2;                     //insert l2 between l1 and prev l1->next
            l2->next = l1_tmp; 

            l1 = l1_tmp;
            l2 = l2_tmp;
        }
    }
};