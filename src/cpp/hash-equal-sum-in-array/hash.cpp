/**
 * Given an array A of integers, find the index of values that satisfy
 * A + B = C + D, where A,B,C & D are integers values in the array. If no
 * solution is possible, return an empty list.
 *
 * Notes:
 * 1) Return the indices `A1 B1 C1 D1`, so that 
 *  A[A1] + A[B1] = A[C1] + A[D1]
 *  A1 < B1, C1 < D1
 *  A1 < C1, B1 != D1, B1 != C1 
 *
 * 2) If there are more than one solutions, 
 * then return the tuple of values which are lexicographical smallest. 
 * 
 * Assume that if we have two solutions
 * S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
 * S2 : A2 B2 C2 D2
 * 
 * then S1 is lexicographically smaller than S2 iff
 * A1 < A2 OR
 * A1 = A2 AND B1 < B2 OR
 * A1 = A2 AND B1 = B2 AND C1 < C2 OR 
 * A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
 *
 * Example:
 * Input: [3, 4, 7, 1, 2, 9, 8]
 * Output: [0, 2, 3, 5] (O index)
 *
 * Time complexity: O(N^2), where N is the length of the array.
 * Explanation: notice, that B1 can be larger than C1 and D1. So, we iterate
 * over the array with two loops and we keep a map<int, pair<int, int>>.
 * The outer loop using a variable, lets say, "i" starts at 0, and the inner
 * loop with a variable, lets say, "j", starts at i + 1. The loops are basically
 * selecting all the possible values for A and B of the equation. The key of the
 * map, is the sum of two values in the array, the value of the map is a pair
 * with the indexes this values are. Each time we find a sum we check to see if
 * the answer we just fuond is lexicographically smaller than the one we had
 * before. Notice, that when we find a sum in the map we do not update our map
 * because the sum we found before has smaller indexes than the one we just
 * found.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void storeAns(vector<int> &ans, vector<int> &v) {
  if (ans.size() != 0) {
    if(v[0] < ans[0] ||
      (v[0] == ans[0] && v[1] < ans[1]) ||
      (v[0] == ans[0] && v[1] == ans[1] && v[2] < ans[2]) ||
      (v[0] == ans[0] && v[1] == ans[1] && v[2] == ans[2] && v[3] < ans[3])) {
      ans[0] = v[0];
      ans[1] = v[1];
      ans[2] = v[2];
      ans[3] = v[3];
    }
  }
  else {
    ans.push_back(v[0]);
    ans.push_back(v[1]);
    ans.push_back(v[2]);
    ans.push_back(v[3]);
  }
}

vector<int> equal(vector<int> &a) {
  if (a.size() < 4) return vector<int>();

  vector<int> ans;
  unordered_map<int, pair<int, int>> m;

  for (int i = 0; i < a.size() - 1; i++) {
    for (int j = i + 1; j < a.size(); j++) {
      int sum = a[i] + a[j];
      unordered_map<int, pair<int, int>>::iterator it = m.find(sum);

      if (it != m.end()) {
        pair<int, int> prevIdx = it->second;
        if (prevIdx.first < i && prevIdx.second != i && prevIdx.second != j) {
          vector<int> t = {prevIdx.first, prevIdx.second, i, j};
          storeAns(ans, t);
        }
      }
      else {
        m[sum] = make_pair(i, j);
      }
    }
  }

  return ans;
}

int main() {
  vector<int> v = {3, 4, 7, 1, 2, 9, 8};

  vector<int> r = equal(v);

  cout << "Array:\n";
  cout << "[ ";
  for (int j = 0; j < v.size(); j++) {
    cout << v[j] << " ";
    if (j != v.size() - 1) cout << "  ";
  }
  cout << "]" << '\n';

  cout << "Answer:\n";
  cout << "[ ";
  for (int j = 0; j < r.size(); j++) {
    cout << r[j] << " ";
    if (j != r.size() - 1) cout << "  ";
  }
  cout << "]" << '\n';

  return 0;
}