class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string c1 = strs[0];
        string c2 = strs[strs.size() - 1];
        int count = 0;
        string save = "";
        for (int i = 0; i < c1.size(); i++)
        {
            if (c1[i] == c2[i])
                save += c1[i];
            else
                break;
        }
        return save;
    }
};