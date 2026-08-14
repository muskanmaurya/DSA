/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return NULL;
        Node* newHead = new Node(head -> val);
        unordered_map<Node*, Node*> mpp;
        mpp[head] = newHead;

        Node* oldTemp = head -> next;
        Node* newTemp = newHead;

        while(oldTemp != nullptr){
            Node* copyNode = new Node(oldTemp -> val);
            mpp[oldTemp] = copyNode;
            newTemp -> next = copyNode;
            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }

        oldTemp = head;
        newTemp = newHead;

        while(oldTemp != nullptr){
            newTemp -> random = mpp[oldTemp -> random];
            oldTemp = oldTemp -> next;
            newTemp = newTemp -> next;
        }

        return newHead;
    }
};