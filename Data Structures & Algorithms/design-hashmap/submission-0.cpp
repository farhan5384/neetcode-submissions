class MyHashMap {
private:
    vector<pair<int, int>> h;

public:
    MyHashMap() {}

    int search(int key) {
        for (int i = 0; i < h.size(); i++) {
            if (h[i].first == key) {
                return i;
            }
        }
        return -1;
    }
    void put(int key, int value) {
        int ans= search(key);

        if ( ans == -1)
            h.push_back({key, value});
        else {
           h[ans].second=value;
        }
    }

    int get(int key) {

        for (int i = 0; i < h.size(); i++) {
            if (h[i].first == key) {
                return h[i].second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int ans= search(key);
        if(ans!=-1){
            h.erase(h.begin() + ans);
        }
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */