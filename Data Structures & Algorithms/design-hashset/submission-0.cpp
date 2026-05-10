class MyHashSet{
private:
    const int size=1000;
    vector<list<int>> table;
    int hash(int key){
        return key%size;
    }
public:
    MyHashSet() {
        table.resize(size);
    }
    
    void add(int key) {
        int h=hash(key);
        for (int x: table[h]){
            if (x==key) return;
        }
        table[h].push_back(key);
    }
    
    void remove(int key) {
        table[hash(key)].remove(key);
    }
    
    bool contains(int key) {
        int h=hash(key);
        for (int x: table[h]){
            if (x==key) return true;
        }
        return false;
    }
};