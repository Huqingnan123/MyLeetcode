
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
        if (head == nullptr || k == 1)     //为空或者k=1不反转
            return head;
        ListNode* first = head;
        int count = 0;                    //计算链表长度（结点个数）
        while (first != nullptr)
        {
            first = first->next;
            count++;
        }
        if (count < k)
            return head;
        int round = count / k;            //整除k计算“k个一组反转的轮数”
        count = 1;
        first = head;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* prevnode = nullptr;
        while (count <= (round * k)) //最多交换round*k个结点顺序，每一轮中left不变，first和right变化
        {
            count++;
            left->next = right->next;
            right->next = first;
            first = right;
            right = left->next;
            if (count == k)      //第一轮的k个结点交换完成，此时第k个结点到第一位，为first
            {
                head = first;    //更新head指针为指向第一组的第k个结点
                prevnode = left; //第一个组原来的第一个已经逆序到第k个，作为下一组k个数的prevnode
                left = right;
                first = right;   //left和right更新到下一组中
                if (right)
                    right = right->next;
                count++;
                continue;
            }
            else if (count > k && count % k == 0)
            {
                prevnode->next = first;  //之后每轮交换完k个节点first还要与prevnode衔接
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