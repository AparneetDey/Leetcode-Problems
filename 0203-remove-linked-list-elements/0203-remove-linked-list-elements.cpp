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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        while(head) {
            if(head->val == val) {
                head = head->next;
                continue;
            }

            ListNode* newNode = new ListNode(head->val);
            temp->next = newNode;
            temp = temp->next;
            head = head->next;
        }

        return ans->next;
    }
};