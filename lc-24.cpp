
// Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* newhead = head->next;  //update newhead to 2nd node
        ListNode* prevnode = nullptr;
        while (left != nullptr && right != nullptr)
        {
            left->next = right->next;
            right->next = left;
            if (prevnode != nullptr)
                prevnode->next = right;     //和之前已经交换的节点连接
            prevnode = left;
            left = left->next;
            if (left != nullptr)
                right = left->next;
        }
        return newhead;
    }
};