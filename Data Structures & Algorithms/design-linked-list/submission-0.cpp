class MyLinkedList
{
private:
    struct Node
    {
        int val;
        Node *next;

        Node(int x) : val(x), next(nullptr) {}
    };

    Node *head;
    int size;

public:
    MyLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        Node *cur = head;
        int i = 0;

        while (i++ < index)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            size++;
            return;
        }
        newnode->next = head;
        head = newnode;
        size++;
    }

    void addAtTail(int val)
    {
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            size++;
            return;
        }
        Node *cur = head;
        while (cur->next)
            cur = cur->next;
        cur->next = newnode;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == size)
        {
            addAtTail(val);
            return;
        }
        Node *newnode = new Node(val);
        Node *cur = head;
        int i = 0;
        while (i++ < index - 1)
            cur = cur->next;
        newnode->next = cur->next;
        cur->next = newnode;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > size - 1)
            return;
        if (index == 0)
        {
            Node *cur = head;
            head = head->next;
            delete cur;
            size--;
            return;
        }
        Node *cur = head;
        int i = 0;
        while (i++ < index - 1)
            cur = cur->next;
        Node *temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        size--;
    }
};