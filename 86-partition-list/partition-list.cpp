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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* btail = dummy1;
        ListNode* atail = dummy2;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* nextNode = curr -> next;
            curr -> next = nullptr;
        
            if(curr -> val < x){
                btail -> next = curr;
                btail = curr;
            }
            else {
                atail -> next = curr;
                atail = curr;
            }
            curr = nextNode;
        }
        btail -> next = dummy2 -> next;
        ListNode* ans = dummy1 -> next;
        delete dummy1;
        delete dummy2;
        return ans;
    }
};