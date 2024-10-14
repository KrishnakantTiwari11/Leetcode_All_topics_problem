class Node {
    public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};
class LRUCache {
public:
    int size;
    unordered_map<int, Node*> m;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    LRUCache(int capacity) { 
        size = capacity;
        head->next=tail;
        tail->prev=head; 
        
        }

        void deletenode(Node*d)
        {
            Node*back=d->prev;
            Node*front=d->next;
            back->next=front;
            front->prev=back;
        }

        void addnode(Node*a)
        {
            Node*temp=head->next;
            head->next=a;
            a->prev=head;
            a->next=temp;
            temp->prev=a;
        }

    int get(int key) {
        if(m.find(key)==m.end())
        {
            return -1;
        }
        Node*dir=m[key];
        deletenode(dir);
        addnode(dir);
        m[key]=head->next;
        return head->next->val;
       }

    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            Node*dir=m[key];
            deletenode(dir);
            dir->val=value;
            addnode(dir);
            m[key]=head->next;
        }
        else if(size==m.size())
        {
           Node*temp=tail->prev;
           deletenode(temp);
           Node*l=new Node(key,value);
           addnode(l);
           m.erase(temp->key);
           m[key]=head->next;
        }
        else
        {
            Node*l=new Node(key,value);
                addnode(l);
                m[key]=l;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */