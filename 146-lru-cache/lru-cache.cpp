class LRUCache {
public:
    vector<pair<int,int>>cache;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        for(int i = 0; i<cache.size(); i++){
            // if we find the val 
            if(cache[i].first == key){
                pair<int,int> temp = cache[i];
                cache.erase(cache.begin() + i);
                cache.push_back(temp);
                return temp.second;

            }
        }
        // if not found 
        return -1;
        
    }
    
    void put(int key, int val) {
        for(int i = 0; i<cache.size(); i++){
            // if we found the existing key then update the val and push to last 
            if(cache[i].first == key){
                cache.erase(cache.begin() + i);
                cache.push_back({key , val});
                return;
            }
        }
        if(cache.size() >= n){
            cache.erase(cache.begin());
            cache.push_back({key , val});
        }
        else{
            cache.push_back({key , val});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */