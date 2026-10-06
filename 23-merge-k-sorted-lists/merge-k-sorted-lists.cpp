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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> list;

        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];

            while(temp != nullptr){
                int val = temp -> val;
                temp = temp -> next;
                list.push_back(val);
            }
        }

        sort(list.begin(), list.end());

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for(int val : list){
            tail -> next = new ListNode(val);
            tail = tail -> next;
        }

        return dummy -> next;
    }
};