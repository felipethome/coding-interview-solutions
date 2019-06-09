/**
 * Given an array and an integer k, find out if an element in the array occurs
 * more than n / k times. In other words, generalize Boyer-Moore Majority vote
 * algorithm.
 *
 * Time complexity: O(N * K), where N is the size of the given array and K
 * the number of parts we want the array to be divided.
 * Space complexity: O(K).
 *
 * Explanation: Look at "N / 3 repetitions in array" problem.
 */

#include <iostream>
#include <vector>

using namespace std;

int findElementIndex(vector<pair<int, int>> &counts, int b) {
  for (int i = 0; i < counts.size(); i++) {
    if (counts[i].first == b) return i;
  }
  return -1;
}

int findEmptyIndex(vector<pair<int, int>> &counts) {
  for (int i = 0; i < counts.size(); i++) {
    if (counts[i].first == -1) return i;
  }
  return -1;
}

void decreaseCounts(vector<pair<int, int>> &counts) {
  for (int i = 0; i < counts.size(); i++) {
    counts[i].second--;
    if (counts[i].second == 0) counts[i].first = -1;
  }
}

vector<int> findMajorities(const vector<int> &a, int b) {
  vector<pair<int, int>> counts(b, {-1, 0});
  vector<int> ans;

  for (int i = 0; i < a.size(); i++) {
    int idx = findElementIndex(counts, a[i]);
    if (idx != -1) {
      counts[idx].second++;
    }
    else {
      int emptyIdx = findEmptyIndex(counts);
      if (emptyIdx != -1) {
        counts[emptyIdx].first = a[i];
        counts[emptyIdx].second++;
      }
      else {
        decreaseCounts(counts);
      }
    }
  }

  for (int i = 0; i < counts.size(); i++) {
    int actualCount = 0;
    for (int j = 0; j < a.size(); j++) {
      if (counts[i].first == a[j]) actualCount++;
    }
    if (actualCount > a.size() / b) ans.push_back(counts[i].first);
  }

  return ans;
}

int main() {
  // vector<int> a = {1};
  // vector<int> a = {1, 2, 3, 4, 5};
  vector<int> a = {1, 2, 3, 1, 1};

  vector<int> r = findMajorities(a, 3);

  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;

  return 0;
}