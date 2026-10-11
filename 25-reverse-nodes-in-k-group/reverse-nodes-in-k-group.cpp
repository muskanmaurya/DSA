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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> ans;
        ListNode* temp = head;

        while(temp != nullptr){
            ans.push_back(temp -> val);
            temp = temp -> next;
        }
        int n = ans.size();

        for(int i = 0; i < n; i += k){
            if(i + k <= n){
            reverse(ans.begin() + i, ans.begin() + i + k);
            }
        }
        ListNode* dummy = new ListNode(0);
        temp = dummy;

        int i = 0;
        while(i < n){
            ListNode* newNode = new ListNode(ans[i]);
            i++;
            temp -> next = newNode;
            temp = temp -> next;
        }
        return dummy -> next;
    }
};