#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
public:
    unordered_map<int, int> hash;
    list<int> LRUkeys;
    int Capacity;

    LRUCache(int capacity) {
        Capacity = capacity;
    }

    int get(int key) {
        if (hash.find(key) != hash.end()) {

            for (auto iter = LRUkeys.begin(); iter != LRUkeys.end(); ++iter)
            {
                if (*iter == key) {
                    LRUkeys.erase(iter);
                    LRUkeys.push_front(key);
                    return hash[key];
                }
            }
        }
        return -1;
    }

    void put(int key, int value) {
        if (get(key) != -1) {
            hash[key] = value;
            return;
        }

        if (hash.size() == Capacity) {
            hash.erase(LRUkeys.back());
            LRUkeys.pop_back();
        }

        hash[key] = value;
        LRUkeys.push_front(key);
    }
};
