/**
 * Given a number N, find all factors of N.
 * 
 * Example:
 * 
 * N = 6 
 * factors = {1, 2, 3, 6}
 * Make sure the returned array is sorted.
 *
 * Time complexity: O(sqrt(N)), where N is the given input.
 *
 * Explanation: the algorithm is based on the fact that you can find all the
 * factors of a number N looking at its possible divisors up to sqrt(N). The
 * other factors will then be the result of the division of N by these factors
 * up to sqrt(N). For example,
 *
 * N = 6
 *
 * sqrt(6) = 2
 * factors up to 2 = 1, 2
 * remaining factors = 6 / 2, 6 / 1 = 3, 6
 * result = 1, 2, 3, 6
 *
 * Just don't forget that when the number has a whole square root that you need
 * to be sure to not include the same factor twice with the above process.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> allFactors(int a) {
  vector<int> ans;

  if (a < 2) {
    ans.push_back(a);
    return ans;
  }

  int r = (int)sqrt(a);

  for (int i = 1; i <= r; i++) {
    if (a % i == 0) ans.push_back(i);
  }

  for (int i = ans.size() - 1; i >= 0; i--) {
    if (a != ans[i] * ans[i]) ans.push_back(a / ans[i]);
  }

  return ans;
}

int main() {
  int a = 82944;

  vector<int> r = allFactors(a);

  for (int e : r) {
    cout << e << " ";
  }
  cout << endl;

  return 0;
}