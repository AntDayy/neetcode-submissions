class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;

        while (true)
        {
            int minVal = 1002;
            int index = -1;

            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i] != nullptr && lists[i]->val < minVal)
                {
                    minVal = lists[i]->val;
                    index = i;
                }
            }

            if (index == -1)
                break;

            tail->next = lists[index];
            tail = tail->next;
            lists[index] = lists[index]->next;
        }

        return dummy.next;
    }
};