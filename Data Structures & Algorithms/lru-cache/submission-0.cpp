
class LRUCache {
private:
    int capacity;

    
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int capacity)
     {
        this->capacity = capacity;
    }

    int get(int key) {

        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }

        auto node = cacheMap[key];

        int value = node->second;

        cacheList.splice(cacheList.end(), cacheList, node);

        return value;
    }

    void put(int key, int value) {

        
        if (cacheMap.find(key) != cacheMap.end()) {

            
            auto node = cacheMap[key];

            node->second = value;

            cacheList.splice(cacheList.end(), cacheList, node);

            return;
        }

        
        if (capacity == 0) {
            return;
        }

     
        if (cacheList.size() == capacity) {

        
            int leastUsedKey = cacheList.front().first;

          
            cacheMap.erase(leastUsedKey);

     
            cacheList.pop_front();
        }

    
        cacheList.push_back({key, value});

        cacheMap[key] = prev(cacheList.end());
    }
};
