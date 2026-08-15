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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while(curr != nullptr){
            ListNode* nextTemp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextTemp;
        }
        ListNode* p1 = head;
        ListNode* p2 = prev;

        while(p2 != nullptr){
            if(p1 -> val != p2 -> val) return false;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return true;
    }
};