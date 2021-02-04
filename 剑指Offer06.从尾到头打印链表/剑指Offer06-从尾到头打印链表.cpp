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
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        for(ListNode* ptr = head; ptr != nullptr; ptr = ptr->next)
            result.push_back(ptr->val);
        reverse(result.begin(), result.end());
        return result;
    }
};