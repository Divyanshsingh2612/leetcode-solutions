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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode(0);   // Dummy node
        ListNode* temp = head;

        int carry = 0;

        while (l1 != NULL || l2 != NULL) {

            int first = 0;
            int second = 0;

            if (l1 != NULL) {
                first = l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                second = l2->val;
                l2 = l2->next;
            }

            int sum = first + second + carry;
            carry = sum / 10;

            ListNode* newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
        }

        // If a carry is left after the loop
        if (carry > 0) {
            temp->next = new ListNode(carry);
        }

        return head->next;
    }
};