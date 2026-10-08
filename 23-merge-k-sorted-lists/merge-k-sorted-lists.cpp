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

    ListNode* merge2Lists(ListNode* list1, ListNode* list2){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(list1 != nullptr && list2 != nullptr){
            if(list1 -> val <= list2 -> val){
                tail -> next = list1;
                list1 = list1 -> next;
            }else {
                tail -> next = list2;
                list2 = list2 -> next;
            }
            tail = tail -> next;
        }
        if(list1 != nullptr) tail -> next = list1;
        if(list2 != nullptr) tail -> next = list2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        ListNode* Head = lists[0];
        for(int i = 1; i < lists.size(); i++){
            Head = merge2Lists(Head, lists[i]);
        }
        return Head;
    }
};