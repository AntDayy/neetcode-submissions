class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> c(256, 0);
        for (int i = 0; i < s.size(); i++)
            c[s[i]]++;
        for (int i = 0; i < t.size(); i++)
            c[t[i]]--;
        for (int i = 0; i < 256; i++)
        {
            if (c[i] != 0)
                return false;
        }
        return true;
    }
};
