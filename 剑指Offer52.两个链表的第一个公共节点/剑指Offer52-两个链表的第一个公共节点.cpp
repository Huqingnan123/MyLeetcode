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
    //�� A �ĳ���Ϊ a + c��B �ĳ���Ϊ b + c������ c Ϊβ���������ֳ��ȣ���֪ a + c + b = b + c + a��
    //���������� A ��ָ����ʵ�������β��ʱ������������ B ��ͷ�����¿�ʼ�������� B��
    //ͬ���أ����������� B ��ָ����ʵ�������β��ʱ������������ A ��ͷ�����¿�ʼ�������� A;
    //�������ܿ��Ʒ��� A �� B ���������ָ����ͬʱ���ʵ�����λ�á�
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        while(l1 != l2)
        {
            //������������ĩβ�ʹ���һ������ʼ����
            l1 = l1 ? l1->next : headB;
            l2 = l2 ? l2->next : headA;
        }
        //�й�����һ�����ཻ������l1�����nullptr
        return l1;
    }
};