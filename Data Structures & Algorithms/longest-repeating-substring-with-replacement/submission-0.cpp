class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> char_count(26, 0);
        int max_freq = 0;
        int max_length = 0;
        int left = 0;
        for (int right = 0; right < (int)s.length(); right++)
        {
            char_count[s[right] - 'A']++;
            max_freq = max(max_freq, char_count[s[right] - 'A']);
            if ((right - left + 1) - max_freq > k)
            {
                char_count[s[left] - 'A']--;
                left++;
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};