
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode* head) {
        bool have_circle = 0;
        if (head == nullptr || head->next == nullptr)
            return have_circle;
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != nullptr && fast != nullptr)
        {
            slow = slow->next;
            if (fast->next != nullptr)
                fast = fast->next->next;
            else
                return have_circle;
            if (fast == slow)
            {
                have_circle = 1;
                break;
            }
        }
        return have_circle;
    }
};