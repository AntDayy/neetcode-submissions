class TimeMap
{
private:
    unordered_map<string, vector<pair<int, string>>> timeMap;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        timeMap[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        auto it = timeMap.find(key);

        if (it == timeMap.end())
            return "";

        const auto &val = it->second;

        if (timestamp < val[0].first)
            return "";

        int left = 0;
        int right = val.size() - 1;
        string res = "";

        while (left <= right)
        {
            int m = left + (right - left) / 2;

            if (val[m].first <= timestamp)
            {
                res = val[m].second;
                left = m + 1;
            }
            else
                right = m - 1;
        }

        return res;
    }
};