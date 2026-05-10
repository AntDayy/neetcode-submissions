class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *res = nullptr;

        while (head != nullptr)
        {
            ListNode *newnode = new ListNode(head->val);

            newnode->next = res;
            res = newnode;
            head = head->next;
        }

        return res;
    }
};