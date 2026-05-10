class MyHashMap{
private:
    vector<vector<pair<int, int>>> map;
    int hash(int key){
        return key%2069;
    }
public:
    MyHashMap() {
        map.resize(2069);
    }

    void put(int key, int value)
    {
        auto& m=map[hash(key)];
        for (int i=0; i<m.size(); i++){
            if (m[i].first==key)
                m[i].second=value;
                return;
        }
        m.push_back({key, value});
    }

    int get(int key)
    {
        auto& m=map[hash(key)];
        for (int i=0; i<m.size(); i++){
            if (m[i].first==key)
                return m[i].second;
        }
        return -1;
    }

    void remove(int key)
    {
        auto& m=map[hash(key)];
        for (int i=0; i<m.size(); i++){
            if (m[i].first==key)   
            m.erase(m.begin()+i);
            break;
        }
    }
};