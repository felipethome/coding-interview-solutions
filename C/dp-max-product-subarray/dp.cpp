/**
 * Find the contiguous subarray within an array (containing at least one number)
 * which has the largest product. Return an integer corresponding to the maximum
 * product possible.
 *
 * Example:
 * Given [2, 3, -2, 4]
 * Return 6. Possible with [2, 3]
 *
 * Time complexity: O(N), where N is the number of elements in the array.
 * Space complexity: O(1).
 *
 * Explanation: this array has positive and negative numbers and zeros. Lets
 * think about what happens when we find a 0. When we are looking at a
 * contiguous subarray and we find a zero it means we need to start all our
 * process again after this zero because any subarray containing 0 will have
 * product 0. Lets think about the negative numbers. Imagine you are looking
 * at a contiguous subarray that do not contain 0. You have two options, and
 * two options only, or you find an odd number of negative numbers or you find
 * an even number of negative numbers. If the number of negative signs are even
 * the maximum product of that contiguous subarray without zeros will be the
 * whole contiguous subarray. If you have an odd number of negative signs so
 * you have two options: or you have your maximum product for that subarray
 * before the first negative number, or after it.
 * So, for each subarray without zeros we need to keep two products: one for
 * the whole subarray and another one that we start to count after the first
 * negative number. At each iteration we store in a variable the maximum of
 * these two products and our previous maximum.
 * Example:
 * 2, 3, -2, 4
 * a[i] = 2 p1: 2 p2: 1 negativeFound: false max: 2
 * a[i] = 3 p1: 6 p2: 1 negativeFound: false max: 6
 * a[i] = -2 p1: -12 p2: 1 negativeFound: true max: 6
 * a[i] = 4 p1: -48 p2: 4 negativeFound: true max: 6
 */

#include <iostream>
#include <vector>

using namespace std;

int maxProduct(const vector<int> &a) {
  if (a.size() == 0) return 0;

  int m = a[0], p1 = 1, p2 = 1;
  bool firstNeg = false;

  for (int i = 0; i < a.size(); i++) {
    m = max(m, a[i]);

    if (a[i] != 0) {
      p1 = p1 * a[i];
      m = max(m, p1);

      if (firstNeg == false && a[i] < 0) firstNeg = true;
      else if (firstNeg) {
        p2 = p2 * a[i];
        m = max(m, p2);
      }
    }
    else {
      firstNeg = false;
      p1 = 1;
      p2 = 1;
    }
  }

  return m;
}

int bruteMaxProduct(const vector<int> &a) {
  if (a.size() == 0) return 0;

  int mp = a[0], acc;

  for (int i = 0; i < a.size(); i++) {
    acc = a[i];
    mp = max(mp, acc);
    for (int j = i + 1; j < a.size(); j++) {
      acc *= a[j];
      mp = max(mp, acc);
    }
  }

  return max(mp, acc);
}

int main() {
  vector<int> a = {2, 3, -2, 4}; // 6
  // vector<int> a = {-4, 0, -5, 0}; // 0
  // vector<int> a = {-2, -3, -3}; // 9
  // vector<int> a = {-3, 3, 3}; // 9
  // vector<int> a = {2, 3, -2, 4, 0, 1, 8, 2, -3, -1}; // 48

  int m = maxProduct(a);

  cout << "max: " << m << endl;

  m = bruteMaxProduct(a);

  cout << "brute max: " << m << endl;

  return 0;
}