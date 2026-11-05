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
    ListNode* MergeList(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(l1 != nullptr && l2 != nullptr){
            if(l1 -> val <= l2 -> val){
                curr -> next = l1;
                l1 = l1 -> next;
            } else {
                curr -> next = l2;
                l2 = l2 -> next;
            }
            curr = curr -> next;
        }

        if (l1 != nullptr) curr -> next = l1;
        else curr -> next = l2;

        return dummy -> next;
    };

    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast != nullptr && fast -> next != nullptr){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        prev -> next = nullptr;

        ListNode* firstHalf = sortList(head);
        ListNode* scndHalf = sortList(slow);

        return MergeList(firstHalf, scndHalf);
    }
};