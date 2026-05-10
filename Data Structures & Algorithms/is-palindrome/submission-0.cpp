class Solution
{
public:
    bool isPalindrome(string s)
    {
        vector<char> c;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
            {
                char save = tolower(s[i]);
                c.push_back(save);
            }
        }
        int left = 0;
        int right = c.size() - 1;
        while (left <= right)
        {
            if (c[left++] != c[right--])
                return false;
        }
        return true;
    }
};