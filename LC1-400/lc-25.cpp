
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1)     //Ϊ�ջ���k=1����ת
            return head;
        ListNode* first = head;
        int count = 0;                    //���������ȣ���������
        while (first != nullptr)
        {
            first = first->next;
            count++;
        }
        if (count < k)
            return head;
        int round = count / k;            //����k���㡰k��һ�鷴ת��������
        count = 1;
        first = head;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* prevnode = nullptr;
        while (count <= (round * k)) //��ཻ��round*k�����˳��ÿһ����left���䣬first��right�仯
        {
            count++;
            left->next = right->next;
            right->next = first;
            first = right;
            right = left->next;
            if (count == k)      //��һ�ֵ�k����㽻����ɣ���ʱ��k����㵽��һλ��Ϊfirst
            {
                head = first;    //����headָ��Ϊָ���һ��ĵ�k�����
                prevnode = left; //��һ����ԭ���ĵ�һ���Ѿ����򵽵�k������Ϊ��һ��k������prevnode
                left = right;
                first = right;   //left��right���µ���һ����
                if (right)
                    right = right->next;
                count++;
                continue;
            }
            else if (count > k && count % k == 0)
            {
                prevnode->next = first;  //֮��ÿ�ֽ�����k���ڵ�first��Ҫ��prevnode�ν�
                prevnode = left;
                left = right;
                first = right;
                if (right)
                    right = right->next;
                count++;
                continue;
            }
        }
        return head;
    }
};