/**
 * Given an array 'A' of integers and another non negative integer k,
 * find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.
 *
 * Example:
 * A : [1 5 3] 
 * k : 2
 *
 * Output : True, because 3 - 1 = 2
 *
 * Time complexity: O(N), where N is the size of the array.
 * Explanation: Iterate over your list. Since we know the value k, at each value
 * of our array we have:
 * aj = arr[i] - k
 * ai = arr[i] + k
 * So, we keep a unordered_set for the values of our array we already checked
 * with our iteration. If we find aj or ai in our set, so return true.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int diffPossible(const vector<int> &num, int diff) {
  if (num.size() < 2 || diff < 0) return false;

  unordered_set<int> S;

  for (int i = 0; i < num.size(); i++) {
    int aj = num[i] - diff;
    int ai = num[i] + diff;

    if (S.find(aj) != S.end()) return true;
    if (S.find(ai) != S.end()) return true;

    S.insert(num[i]);
  }

  return false;
}

// int diffPossible(const vector<int> &a, int b) {
//   if (a.size() <= 1) return 0;

//   unordered_map<int, int> m;
  
//   for (int i = 0; i < a.size(); i++) {
//     m.insert(make_pair(a[i], i));
//   }
  
//   for (int i = 0; i < a.size(); i++) {
//     int diff = a[i] - b;
//     unordered_map<int, int>::const_iterator it = m.find(diff);
//     if (it != m.end() && it->second != i) return 1;
//   }
  
//   return 0;
// }

int main() {
  // vector<int> v = {3, 5, 6, 10, 11, 13, 14};
  vector<int> v = {1, 3, 2};
  int a;

  cout << "Write the difference you are looking for: ";
  cin >> a;
  cout << "\n";

  int diffExists = diffPossible(v, a);

  if (diffExists) cout << "\nThe diff is possible\n";
  else cout << "\nThe diff is not possible\n";

  return 0;
}