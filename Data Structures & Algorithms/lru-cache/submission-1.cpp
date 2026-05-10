struct Node
{
    pair<int, int> val;
    Node *next;
    Node *prev;

    Node()
    {
        this->val = {0, 0};
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int key, int value)
    {
        this->val = {key, value};
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LRUCache
{
private:
    unordered_map<int, Node *> map;
    int n;
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    LRUCache(int capacity)
    {
        this->n = capacity;
        map.reserve(capacity);
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            Node *cur = map[key];
            if (cur != head)
            {
                if (cur == tail)
                {
                    tail = cur->prev;
                    cur->prev->next = nullptr;
                }
                else
                {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                }
                cur->next = head;
                cur->prev = nullptr;
                head->prev = cur;
                head = cur;
            }
            return head->val.second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            map[key]->val.second = value;
            get(key);
            return;
        }

        if (map.size() >= this->n)
        {
            Node *oldTail = tail;
            map.erase(oldTail->val.first);

            tail = tail->prev;
            if (tail != nullptr)
                tail->next = nullptr;
            else
                head = nullptr;

            delete oldTail;
        }

        Node *newnode = new Node(key, value);
        map.insert({key, newnode});

        if (head == nullptr)
        {
            head = newnode;
            tail = head;
        }
        else
        {
            newnode->next = head;
            newnode->prev = nullptr;
            head->prev = newnode;
            head = newnode;
        }
    }
};