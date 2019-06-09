/**
 * Binary Min Heap with Decrease operation.
 *
 * Operations:
 * contains(key): check if a key is in the heap. O(1).
 * push(key): add an element to the heap. O(logN).
 * extractMin(key): Get and remove the min element. O(logN).
 * getMin(key): Get min element. O(1).
 * decrease(key, newWeight): Decrease an element in the heap. O(logN).
 * N is the number of elements in the heap.
 *
 * In the decrease operation we just update the value and swap it with its
 * parent until we reach the heap's root or the parent is less greater than the
 * element we updated.
 *
 * In the extractMin operation we store the first element of the heap, replace
 * this first element with the last one, and pop the last element from the heap.
 * Then, we perform "sift down" to make the heap valid again.
 *
 * Note: the implementation is in the header file because classes using
 * templates can not have their definitions outside the header if you are
 * planning to use the code as an include.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template<class T> class MinHeap {
  private:
    unordered_map<T, int> nodeMap;
    vector<pair<T, int>> h;

  public:
    bool empty();
    bool contains(T k);
    void heapify(int idx);
    void push(T k, int w);
    void decreaseKey(T k, int newWeight);
    pair<T, int> getMin();
    pair<T, int> extractMin();
    int getWeight(T k);
    void printHeap();
    void printMap();
};

/* --- Implementation --- */

template<class T>
bool MinHeap<T>::empty() {
  return h.size() == 0;
}

template<class T>
bool MinHeap<T>::contains(T k) {
  if (nodeMap.find(k) != nodeMap.end()) return true;
  return false;
}

// Correct a single violation of the heap property. 
template<class T>
void MinHeap<T>::heapify(int idx) {
  // Repeat while the element has a parent AND the weight of the parent is
  // greater than the weight of the child.
  while ((idx - 1) / 2 >= 0 && h[(idx - 1) / 2].second > h[idx].second) {
    pair<T, int> parent = h[(idx - 1) / 2], child = h[idx];

    // Swap parent and child.
    swap(h[(idx - 1) / 2], h[idx]);

    // The position of the parent is now the position of the child, and the
    // position of the child is now the position of the parent.
    nodeMap[parent.first] = idx;
    nodeMap[child.first] = (idx - 1) / 2;

    // Point to the parent and continue the loop.
    idx = (idx - 1) / 2;
  }
}

template<class T>
void MinHeap<T>::push(T k, int w) {
  if (contains(k)) return;

  h.push_back({k, w});
  int idx = h.size() - 1;
  nodeMap[k] = idx;

  heapify(idx);
}

template<class T>
void MinHeap<T>::decreaseKey(T k, int newWeight) {
  int idx = nodeMap[k];
  h[idx].second = newWeight;
  heapify(idx);
}

template<class T>
pair<T, int> MinHeap<T>::getMin() {
  return h[0];
}

template<class T>
pair<T, int> MinHeap<T>::extractMin() {
  pair<T, int> minNode = h[0];

  swap(h[0], h[h.size() - 1]);
  nodeMap[h[0].first] = 0;
  h.pop_back();
  nodeMap.erase(minNode.first);

  int curr = 0;

  // Sift down.
  while ((2 * curr) + 1 < h.size()) {
    int left = (2 * curr) + 1, right = (2 * curr) + 2;

    // If the current element is greater than its left and right children stop
    // the loop.
    if (h[curr].second < h[left].second && (right >= h.size() ||
      (right < h.size() && h[curr].second < h[right].second))) {
      break;
    }

    // Get the smallest of the children.
    int smallest = left;
    if (right < h.size() && h[right].second < h[left].second) smallest = right;

    // Swap the smallest child with the parent.
    pair<T, int> parent = h[curr], child = h[smallest];
    swap(h[curr], h[smallest]);
    nodeMap[parent.first] = smallest;
    nodeMap[child.first] = curr;

    // Point the current element to the smallest of the children and continue
    // the loop.
    curr = smallest;
  }

  return minNode;
}

template<class T>
int MinHeap<T>::getWeight(T k) {
  return h[nodeMap[k]].second;
}

template<class T>
void MinHeap<T>::printHeap() {
  cout << "Heap:" << endl;
  for (int i = 0; i < h.size(); i++) {
    cout << "pos: " << i << " vertex: " << h[i].first << " weight: " << h[i].second << endl;
  }
  cout << endl;
}

template<class T>
void MinHeap<T>::printMap() {
  cout << "Map:" << endl;
  for (auto it = nodeMap.begin(); it != nodeMap.end(); it++) {
    cout << "vertex: " << it->first << " pos: " << it->second << endl;
  }
  cout << endl;
}

// int main() {
//   MinHeap<int> heap;

//   cout << "empty: " << heap.empty() << endl << endl;

//   heap.push(0, 3);
//   heap.push(1, 4);
//   heap.push(2, 2);
//   heap.push(3, 1);
//   heap.push(4, 10);
//   heap.push(5, 5);

//   heap.printHeap();
//   heap.printMap();
  
//   cout << "empty: " << heap.empty() << endl << endl;

//   cout << "min: " << heap.extractMin().second << endl;
//   cout << "min: " << heap.extractMin().second << endl;
//   cout << "min: " << heap.extractMin().second << endl;
//   cout << endl;

//   heap.printHeap();
//   heap.printMap();

//   heap.decreaseKey(5, 2);

//   heap.printHeap();
//   heap.printMap();

//   heap.decreaseKey(4, 1);

//   heap.printHeap();
//   heap.printMap();

//   cout << "weight: " << heap.getWeight(5) << endl << endl;

//   return 0;
// }