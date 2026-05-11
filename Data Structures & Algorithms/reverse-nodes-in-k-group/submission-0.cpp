class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        deque<ListNode *> de;
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (head)
        {
            de.push_back(head);
            head = head->next;

            if (de.size() == k)
            {
                while (!de.empty())
                {
                    tail->next = de.back();
                    tail = tail->next;
                    tail->next = nullptr;
                    de.pop_back();
                }
            }
        }

        while (!de.empty())
        {
            tail->next = de.front();
            tail = tail->next;
            tail->next = nullptr;
            de.pop_front();
        }

        return dummy.next;
    }
};