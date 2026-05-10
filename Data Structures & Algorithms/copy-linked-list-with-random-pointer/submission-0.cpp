class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;

        // Bước 1: Tạo các node bản sao xen kẽ
        Node *curr = head;
        while (curr)
        {
            Node *new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }

        // Bước 2: Gán con trỏ random cho node bản sao
        curr = head;
        while (curr)
        {
            if (curr->random)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Bước 3: Tách danh sách
        curr = head;
        Node *copied_head = head->next;

        while (curr)
        {
            Node *copy_node = curr->next;
            curr->next = copy_node->next; // Khôi phục danh sách gốc
            if (copy_node->next)
            {
                copy_node->next = copy_node->next->next; // Nối danh sách bản sao
            }
            curr = curr->next;
        }

        return copied_head;
    }
};