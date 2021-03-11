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
    void deleteNode(ListNode* node) {
        //用后一个结点覆盖此结点，跳过后一结点
        node->val = node->next->val;
        node->next = node->next->next;
    }
};