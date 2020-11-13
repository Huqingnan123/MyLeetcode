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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        //��������������������ż���ڵ�
        ListNode* second = head->next;  
        //odd-->even-->nullptr��ʱ������任��even-->odd->nulllptr��ʱ��Ҫ����
        int number = 1;
        while(even != nullptr && even->next != nullptr)
        {
            //even��odd֮��ʱ���ƶ�oddָ���ϵ
            if(number % 2)
            {
                odd->next = even->next;
                odd = even->next;
            }
            //even��odd֮ǰʱ���ƶ�evenָ��
            else
            {
                even->next = odd->next;
                even = odd->next; 
            }
            number++;
        }
        odd->next = second;
        return head;
    }
};