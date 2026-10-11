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
        //Bruteforce
        vector<int> ans;

        for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
            ans.push_back(temp->val);
        }

        int n = ans.size();
        for (int i = 0; i + k <= n; i += k) {
            reverse(ans.begin() + i, ans.begin() + i + k);
        }

        ListNode dummy(0);
        ListNode* temp = &dummy;
        for (int val : ans) {
            temp->next = new ListNode(val);
            temp = temp->next;
        }

        return dummy.next;
    }
};