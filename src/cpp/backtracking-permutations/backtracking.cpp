/*
 * Given a collection of numbers, return all possible permutations.
 *
 * Example:
 * [1,2,3] will have the following permutations:
 * 
 * [1,2,3]
 * [1,3,2]
 * [2,1,3] 
 * [2,3,1] 
 * [3,1,2] 
 * [3,2,1]
 *
 * Time complexity: O(N!), where N is the size of the given list.
 *
 * Explanation: for each number in our list we let it assume the position our
 * current function call is dealing with. Then, we call again our function, but
 * we increment the position so the number we just put in that position will not
 * be swapped in this next function call. When we come back from a function is
 * important we swap back the number to its original position in this function
 * call we are now at.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void _permute(vector<int> &c, int s, vector<vector<int>> &ans) {
  if (s == c.size() - 1) {
    ans.push_back(c);
    return;
  }

  for (int i = s; i < c.size(); i++) {
    swap(c[s], c[i]);
    _permute(c, s + 1, ans);
    swap(c[s], c[i]);
  }
}

vector<vector<int>> permute(vector<int> &a) {
  vector<vector<int>> ans;

  if (a.size() == 0) return ans;

  sort(a.begin(), a.end());
  _permute(a, 0, ans);

  return ans;
}

// vector<vector<int>> _permute(vector<vector<int>> &c, int a) {
//   vector<vector<int>> r;
//   int i, j, k;

//   for (i = 0; i < c.size(); i++) {
//     for (j = 0; j < c[i].size() + 1; j++) {
//       vector<int> t;
//       for (k = 0; k < c[i].size(); k++) {
//         if (k == j) t.push_back(a);
//         t.push_back(c[i][k]);
//       }
//       if (k == j) t.push_back(a);
//       r.push_back(t);
//     }
//   }

//   return r;
// }

// vector<vector<int>> permute(vector<int> &a) {
//   vector<vector<int>> ans;
//   vector<int> t;

//   if (a.size() == 0) return ans;

//   ans.push_back(t);  
//   for (int i = 0; i < a.size(); i++) {
//     ans = _permute(ans, a[i]);
//   }
//   sort(ans.begin(), ans.end());

//   return ans;
// }

int main() {
  // vector<int> a;
  // vector<int> a = {1};
  vector<int> a = {1, 2, 3};

  vector<vector<int>> r = permute(a);

  cout << "Answer has " << r.size() << " vectors:" << '\n';
  for (int i = 0; i < r.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < r[i].size(); j++) {
      cout << r[i][j] << ' ';
    }
    cout << "]" << '\n';
  }

  // cout << "Count: " << count2 << '\n';

  return 0;
}