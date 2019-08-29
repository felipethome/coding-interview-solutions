/*
 * Given a set of distinct integers, S, return all possible subsets.
 * Conditions:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * Also, the subsets should be sorted in ascending (lexicographic) order.
 * The given list is not necessarily sorted.
 *
 * Example:
 * If S = [1,2,3], a solution is:
 * [
 *   [],
 *   [1],
 *   [1, 2],
 *   [1, 2, 3],
 *   [1, 3],
 *   [2],
 *   [2, 3],
 *   [3],
 * ]
 *
 * Time complexity: Without taking into consideration the sorting process,
 * O(2^(N + 1)) in the recursion case, O(2^N * N) in the iterative case, where N
 * is the size of the give list.
 * 
 * Explanation:
 * 
 * Use a sort algorithm to sort the given list.
 * 
 * Iterative: we have 2^N possible different subsets, so we can iterate from
 * 0 to (2^N - 1) using a variable "i" and check the setted bits of "i". Then,
 * we iterate from 0 to N - 1 using a variable "j". "j" gives us the a index
 * from our original set, and the setted bits (bits with the value 1) from "i"
 * give us all the possible combinations of subsets, where each bit position is
 * a index from our original set. So we check to see if (1 << j) is setted in
 * "i" and if it is we add to our current subset.
 *
 * Recursive: we have two options for each element in the set: or we add it, or
 * we not. Make a recursive call for each one of these possibilities.
 *
 * Finally, use a sort algorithm to sort the answer.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void _subsets(vector<int> &a, int i, vector<int> &c, vector<vector<int>> &ans) {
  if (i >= a.size()) {
    ans.push_back(c);
    return;
  }

  _subsets(a, i + 1, c, ans);

  c.push_back(a[i]);
  _subsets(a, i + 1, c, ans);
  c.pop_back();
}

vector<vector<int>> subsets(vector<int> &a) {
  vector<vector<int>> ans;
  vector<int> c;

  sort(a.begin(), a.end());
  _subsets(a, 0, c, ans);
  sort(ans.begin(), ans.end());

  return ans;
}

// vector<vector<int>> subsets(vector<int> &a) {
//   vector<vector<int>> ans;
//   int n = a.size();

//   sort(a.begin(), a.end());

//   for (int i = 0; i < (1 << n); i++) {
//     vector<int> t;

//     for (int j = 0; j < n; j++) {
//       if (i & (1 << j)) t.push_back(a[j]);
//     }

//     ans.push_back(t);
//   }

//   sort(ans.begin(), ans.end());
  
//   return ans;
// }

int main() {
  vector<int> a = {1, 2, 3, 4};
  // vector<int> a;
  // vector<int> a = {1};

  vector<vector<int>> r = subsets(a);

  cout << "Answer has " << r.size() << " vectors:" << '\n';
  for (int i = 0; i < r.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << ' ';
    }
    cout << "]" << '\n';
  }

  return 0;
}