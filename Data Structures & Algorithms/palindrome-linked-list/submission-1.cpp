class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (v[i] != v[n - i - 1])
                return false;
        }
        return true;
    }
};