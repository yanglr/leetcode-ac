#include<iostream>
#include<algorithm>
#include<list>
#include<unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        const auto it = map.find(key);
        if (it == map.cend()) return -1;
 
        // 使用splice函数将这个entry移到缓存的最前面
        caches.splice(caches.begin(), caches, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {        
        const auto it = map.find(key);
        
        if (it != map.cend()) {   // 如果key已经存在于map中
            // 更新kv pair中的value
            it->second->second = value;
            // 使用splice函数将这个entry移到缓存的最前面
            caches.splice(caches.begin(), caches, it->second);
            return;
        }
        
        // 如果(key不存在，且)容量到上限时，则删除最早的entry
        if (caches.size() == cap) {
            const auto& oldestPair = caches.back();
            map.erase(oldestPair.first); // 从map中删除最早的entry的key
            caches.pop_back();
        }
        
        // 使用list容器的emplace_front函数将entry插入到cache的第一个位置并更新mapping.
        caches.emplace_front(key, value);
        map[key] = caches.begin();
    }

private:
    int cap;
    list<pair<int,int>> caches;
    unordered_map<int, list<pair<int,int>>::iterator> map;  // list<pair<int,int>>::iterator是迭代器位置，类似于"指针"
};
 
/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache obj = new LRUCache(capacity);
* int paramap1 = obj.get(key);
* obj.put(key,value);
*/

// Test
int main()
{
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // 缓存是 {1=1}
    lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
    int res1 = lRUCache->get(1);    // 返回 1
    cout << res1 << endl;
    lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    int res2 = lRUCache->get(2);    // 返回 -1 (未找到)
    cout << res2 << endl;
    lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    int res3 = lRUCache->get(1);    // 返回 -1 (未找到)
    cout << res3 << endl;    
    int res4 = lRUCache->get(3);    // 返回 3
    cout << res4 << endl;    
    int res5 = lRUCache->get(4);    // 返回 4
    cout << res5 << endl;    

    return 0;
}