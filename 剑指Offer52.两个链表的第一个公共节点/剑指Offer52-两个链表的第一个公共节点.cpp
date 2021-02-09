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
    //设 A 的长度为 a + c，B 的长度为 b + c，其中 c 为尾部公共部分长度，可知 a + c + b = b + c + a。
    //当访问链表 A 的指针访问到其链表尾部时，令它从链表 B 的头部重新开始访问链表 B；
    //同样地，当访问链表 B 的指针访问到其链表尾部时，令它从链表 A 的头部重新开始访问链表 A;
    //这样就能控制访问 A 和 B 两个链表的指针能同时访问到交点位置。
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while(l1 != l2)
        {
            //当自身链表到达末尾就从另一条链表开始遍历
            l1 = l1 ? l1->next : headB;
            l2 = l2 ? l2->next : headA;
        }
        //有公共点一定会相交，否则l1最后还是nullptr
        return l1;
    }
};