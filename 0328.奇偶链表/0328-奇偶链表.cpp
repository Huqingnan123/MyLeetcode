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
        //用于最后：奇数结点连接上偶数节点
        ListNode* second = head->next;  
        //odd-->even-->nullptr的时候结束变换，even-->odd->nulllptr的时候还要继续
        int number = 1;
        while(even != nullptr && even->next != nullptr)
        {
            //even在odd之后时，移动odd指针关系
            if(number % 2)
            {
                odd->next = even->next;
                odd = even->next;
            }
            //even在odd之前时，移动even指针
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