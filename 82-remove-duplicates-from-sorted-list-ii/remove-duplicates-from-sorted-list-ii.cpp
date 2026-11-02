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
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* curr = dummy;

        while(curr -> next != NULL && curr -> next -> next != NULL){
            if(curr -> next -> val == curr -> next -> next -> val){
                int dupVal = curr -> next -> val;

            while(curr -> next != NULL && curr -> next -> val == dupVal){
                ListNode* todlt = curr -> next;
                curr -> next = curr -> next -> next;
            }
        }else {
            curr = curr -> next;
            }
        }
    return dummy -> next;
    }
};