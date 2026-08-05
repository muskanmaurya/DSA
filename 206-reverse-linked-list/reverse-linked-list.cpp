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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        vector<int> arr;

        if (head == NULL || head->next == NULL) {
            return head;
        }

        while(temp != NULL){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }

        reverse(arr.begin(), arr.end());

        ListNode* newHead = new ListNode(arr[0]);
        ListNode* curr = newHead;

        for(int i = 1; i < arr.size(); i++){
            curr -> next = new ListNode(arr[i]);
            curr = curr -> next;
        }
        return newHead;
    }
};