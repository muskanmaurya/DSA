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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(temp1 != nullptr || temp2 != nullptr || carry != 0){
            int val1 = (temp1 != nullptr) ? temp1 -> val : 0;
            int val2 = (temp2 != nullptr) ? temp2 -> val : 0;

            int sum = val1 + val2 + carry;
            carry = sum/10;

            tail -> next = new ListNode(sum % 10);
            tail = tail -> next;

            if (temp1 != nullptr) temp1 = temp1->next;
            if (temp2 != nullptr) temp2 = temp2->next;
        }
    return dummy.next;
    }
};