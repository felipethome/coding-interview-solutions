/**
 * You are given an array of N integers, A1, A2 ,…, AN and an integer K.
 * Return the of count of distinct numbers in all windows of size K.
 * Formally, return an array of size N-K+1 where i’th element in this array
 * contains number of distinct elements in sequence Ai, Ai+1 ,…, Ai+k-1.
 *
 * Note:
 * If K > N, return empty array.
 *
 * Example,
 * A = [1, 2, 1, 3, 4, 3] and K = 3
 * All windows of size K are:
 * [1, 2, 1]
 * [2, 1, 3]
 * [1, 3, 4]
 * [3, 4, 3]
 * So, we return an array [2, 3, 3, 2].
 *
 * Time complexity: O(N), where N is the size of the given array.
 *
 * Explanation: start with an empty hashmap where the keys are the elements of
 * the array and the values are counters for how many times these elements
 * appeared. Each time you arrive at the start of a new window you will
 * decrement the first element of the previous window and add (or increment if
 * it already exists in the hashmap) the the last element of the current window,
 * both, in the hashmap. For each window the number of distinct elements is the
 * size of the hashmap. When you are doing the process of removing or
 * decrementing the first element of the previous window don't forget that when
 * the counter becomes zero you must delete the entry from the hashmap.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> dNums(vector<int> &a, int k) {
  vector<int> ans;
  unordered_map<int, int> m;

  if (k <= 0 || k > a.size()) return ans;

  for (int i = 0; i < k; i++) {
    if (m.find(a[i]) != m.end()) m[a[i]] += 1;
    else m[a[i]] = 1;
  }

  ans.push_back(m.size());
  
  int prevFirst = a[0];
  for (int i = 1; i <= a.size() - k; i++) {
    int last = a[i + k - 1];

    if (m.find(prevFirst) != m.end()) {
      m[prevFirst] -= 1;
      if (m[prevFirst] <= 0) m.erase(prevFirst);
    }

    if (m.find(last) != m.end()) m[last] += 1;
    else m[last] = 1;

    ans.push_back(m.size());

    prevFirst = a[i];
  }

  return ans;
}

int main() {
  vector<int> a = {1, 2, 1, 3, 4, 3};
  int k = 3;

  cout << "Array: " << endl;
  cout << "[ ";
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
    if (i != a.size() - 1) cout << "  ";
  }
  cout << "]" << endl;

  vector<int> r = dNums(a, k);

  cout << "Answer: " << endl;
  cout << "[ ";
  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
    if (i != r.size() - 1) cout << "  ";
  }
  cout << "]" << endl;

  return 0;
}