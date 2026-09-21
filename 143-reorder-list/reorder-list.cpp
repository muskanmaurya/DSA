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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* temp = head;
        int cnt = 0;
        while(temp != nullptr){
            vec.push_back(temp);
            temp = temp -> next;
        }

        int l = 0, r = vec.size() - 1;
        while(l < r){
            vec[l] -> next = vec[r];
            l++;

            if(l == r) break;

            vec[r] -> next = vec[l];
            r--;
        }
        vec[l] -> next = nullptr;
     }
};