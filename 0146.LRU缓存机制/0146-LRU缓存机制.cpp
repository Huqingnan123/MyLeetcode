class LRUCache {
public:
    int cap;
    list<pair<int,int>> myList;
    unordered_map<int, list<pair<int,int>>::iterator> hash;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end())
            return -1;
        myList.splice(myList.begin(), myList, hash[key]);
        hash[key] = myList.begin();
        return myList.front().second;
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end())
            myList.erase(hash[key]);
        myList.push_front(make_pair(key, value));
        hash[key] = myList.begin();
        //LRU原则清除元素
        if(myList.size() > cap) {
            int loser = myList.back().first;
            myList.pop_back();
            hash.erase(loser);
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */