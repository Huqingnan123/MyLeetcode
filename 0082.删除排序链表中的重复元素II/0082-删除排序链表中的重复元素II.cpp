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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur != nullptr && cur->next != nullptr) {
            // 存在连续重复结点则全部删除
            if(cur->val == cur->next->val) {
                int value = cur->val;
                while(cur != nullptr && cur->val == value) {
                    cur = cur->next;
                }
                if(pre == nullptr)
                    head = cur;
                else
                    pre->next = cur;
            }
            // 无重复，cur和pre往后移
            else {
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};