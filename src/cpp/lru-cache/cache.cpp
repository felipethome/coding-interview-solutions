/**
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and set.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present.
 * When the cache reaches its capacity, it should invalidate the least recently
 * used item before inserting the new item.
 *
 * The LRUCache will be initialized with an integer corresponding to its
 * capacity. Capacity indicates the maximum number of unique keys it can hold at
 * a time.
 *
 * Example:
 * capacity = 2
 * set(1, 10)
 * set(5, 12)
 * get(5)        returns 12
 * get(1)        returns 10
 * get(10)       returns -1
 * set(6, 14)    this pushes out key = 5 as LRU is full. 
 * get(5)        returns -1 
 *
 * Time complexity: O(1) for both operations "set" and "get".
 * Explanation: use a hashmap and a doubly linked list. The hashmap will allow
 * us to get the elements in O(1), but the hashmap alone would not allow us to
 * set a value in O(1), because we would need to look for the LRU element. If we
 * use a doubly linked list to store a values we can easily reorder our elements
 * in constant time each time we set or we get a value. The hashmap then needs
 * to store the pointer to the linked list node instead of the value itself.
 * The reorder of our linked list is just putting the just used element in the
 * front of the list for a LRU cache. We could use the same approach for a LFU
 * cache and just the reorder would change.
 */

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
  int c;
  list<pair<int, int>> l;
  unordered_map<int, list<pair<int, int>>::iterator> m;

public:
  LRUCache(int capacity) {
    c = capacity;
    print();
  }
  
  int get(int key) {
    unordered_map<int, list<pair<int, int>>::iterator>::iterator mit;
    mit = m.find(key);

    if (mit == m.end()) return -1;

    list<pair<int, int>>::iterator lit = mit->second;
    l.push_front(make_pair(key, mit->second->second));
    l.erase(lit);
    mit->second = l.begin();
    print();

    return mit->second->second;
  }
  
  void set(int key, int value) {
    unordered_map<int, list<pair<int, int>>::iterator>::iterator mit;
    mit = m.find(key);
    
    if (mit != m.end()) {
      list<pair<int, int>>::iterator lit = mit->second;
      l.erase(lit);
      l.push_front(make_pair(key, value));
      mit->second = l.begin();
    }
    else {
      if (l.size() == c && l.size() != 0) {
        list<pair<int, int>>::iterator eit = l.end();
        --eit;
        m.erase(eit->first);
        l.erase(eit);
      }
      l.push_front(make_pair(key, value));
      list<pair<int, int>>::iterator fit = l.begin();
      m[key] = fit;
    }
    print();
  }

  void print() {
    list<pair<int, int>>::iterator it = l.begin();

    cout << "List: ";
    for (; it != l.end(); it++) {
      cout << it->first << ":" << it->second << " ";
    }
    cout << endl;

    cout << "Map size: " << m.size() << endl;
  }
};

int main() {
  LRUCache *cache = new LRUCache(3);

  cache->set(1, 101);
  cache->set(2, 102);
  cache->set(3, 103);

  cache->get(1);
  cache->set(4, 104);
  cache->get(0);
  cache->set(3, 1033);
  cache->set(2, 1022);

  return 0;
}