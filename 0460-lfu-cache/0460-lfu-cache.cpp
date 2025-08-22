class LFUCache {
    private:
    int capacity, minFreq;
    unordered_map<int, pair<int,int>> keyTable; // key -> {value, freq}
    unordered_map<int, list<int>> freqTable;   // freq -> keys (LRU order)
    unordered_map<int, list<int>::iterator> iterTable; // key -> iterator in freqTable   [freq]
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if (keyTable.find(key) == keyTable.end()) 
            return -1;

        auto [value, freq] = keyTable[key];
        
        // Remove key from old freq list
        freqTable[freq].erase(iterTable[key]);
        if (freqTable[freq].empty()) {
            freqTable.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // Insert key into new freq list
        freqTable[freq+1].push_front(key);
        iterTable[key] = freqTable[freq+1].begin();
        keyTable[key].second++; // increase frequency

        return value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        // If already exists, update value & increase frequency
        if (keyTable.find(key) != keyTable.end()) {
            keyTable[key].first = value;
            get(key); // re-use get to update frequency
            return;
        }

        // If full, evict LFU key
        if (keyTable.size() == capacity) {
            int evictKey = freqTable[minFreq].back();
            freqTable[minFreq].pop_back();
            if (freqTable[minFreq].empty()) freqTable.erase(minFreq);
            keyTable.erase(evictKey);
            iterTable.erase(evictKey);
        }

        // Insert new key with freq = 1
        keyTable[key] = {value, 1};
        freqTable[1].push_front(key);
        iterTable[key] = freqTable[1].begin();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */