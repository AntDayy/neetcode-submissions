class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;

        vector<int> v;
        ListNode *temp = head;

        int i = 1;
        while (i < left)
        {
            temp = temp->next;
            ++i;
        }
        ListNode *cur = temp;

        for (int i = left; i <= right; i++)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }

        reverse(v.begin(), v.end());
        temp = cur;
        for (int i = 0; i < v.size(); i++)
        {
            temp->val = v[i];
            temp = temp->next;
        }

        return head;
    }
};