class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 0;
        ListNode *cur = head;

        while (cur)
        {
            ++size;
            cur = cur->next;
        }

        if (size == n)
        {
            head = head->next;
            return head;
        }

        cur = head;
        for (int i = 0; i < size - n - 1; i++)
            cur = cur->next;

        cur->next = cur->next->next;

        return head;
    }
};