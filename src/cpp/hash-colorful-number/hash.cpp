/**
 * For Given Number N find if its COLORFUL number or not. Return 0/1.
 *
 * A number can be broken into different contiguous sub-subsequence parts. 
 * Suppose, a number 3245 can be broken into parts like:
 * 3 2 4 5 32 24 45 324 245. 
 * And this number is a COLORFUL number, since product of every digit of a
 * contiguous subsequence is different.
 *
 * Example:
 * N = 23
 * 2 3 23
 * 2 -> 2
 * 3 -> 3
 * 23 -> 6
 * this number is a COLORFUL number since product of every digit of a
 * sub-sequence are different. 
 * Output : 1
 *
 * Time complexity: O(N), where N is the number of digits.
 * Explanation:
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> getDigits(int a) {
  vector<int> digits;

  while (a > 0)  {
    digits.push_back(a % 10);
    a /= 10;
  }

  return digits;
}

int colorful(int a) {
  vector<int> d = getDigits(a);
  unordered_set<int> s;

  for (int i = 0; i < d.size(); i++) {
    int product = 1;

    for (int j = i; j >= 0; j--) {
      product *= d[j];
      if (s.find(product) != s.end()) return 0;
      s.insert(product);
    }
  }

  return 1;
}

int main() {
  int a;

  cout << "Write the number you want to check if it is colorful: ";
  cin >> a;
  cout << "\n";

  int isColorful = colorful(a);

  if (isColorful) cout << "\nThe number is colorful\n";
  else cout << "\nThe number is not colorful\n";

  return 0;
}