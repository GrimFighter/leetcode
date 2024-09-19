class LRUCache {
public:

    class Node{
        public:
            int key;
            int val;

            Node* prev; Node* next;

            Node(int key, int value)
            {
                this->key=key;
                val=value;
            }
    };

    Node* head= new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int capacity;

    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next=tail;
        tail->prev=head;

        
    }
    
    void addNode(Node* newnode)
    {
        Node* temp=head->next;

        newnode->next=temp;
        newnode->prev=head;

        head->next= newnode;
        temp->prev=newnode;
    }

    void deleteNode(Node* delnode)
    {
        Node* prev=delnode->prev;
        Node* nextt= delnode->next;

        prev->next=nextt;
        nextt->prev=prev;
    }
    int get(int key) {
        if( m.find(key)!= m.end())
        {
            Node* res = m[key];
            int ans = res->val;

            m.erase(key);
            deleteNode(res);
            addNode(res);

            m[key] = head->next;
            return ans;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if( m.find(key) != m.end())
        {
            Node* res = m[key];
            m.erase(key);
            deleteNode(res);
            
        }

        if( m.size() == capacity)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */