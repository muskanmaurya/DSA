class LRUCache {
public:
    class Node{
    public:    
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mpp;
    int limit;

    void addNode(Node* newNode){
        Node* oldNext = head -> next;

        head -> next = newNode;
        oldNext -> prev = newNode;

        newNode -> next = oldNext;
        newNode -> prev = head;
    }

    void dltNode(Node* oldNode){
        Node* oldPrev = oldNode -> prev;
        Node* oldNext = oldNode -> next;
        
        oldPrev -> next = oldNext;
        oldNext -> prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head -> next = tail;
        tail -> prev = head;  
    }
    
    int get(int key) {
        if(!mpp.contains(key)) return -1;

        Node* ansNode = mpp[key];
        int ans = ansNode -> val;

        mpp.erase(key);
        dltNode(ansNode);

        addNode(ansNode);
        mpp[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if(mpp.contains(key)){
            Node* oldNode = mpp[key];
            dltNode(oldNode);
            mpp.erase(key);
            delete oldNode;
        }

        if(mpp.size() == limit){
            mpp.erase(tail -> prev -> key);
            Node* toDelete = tail -> prev;
            dltNode(toDelete);
            delete toDelete;
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mpp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */