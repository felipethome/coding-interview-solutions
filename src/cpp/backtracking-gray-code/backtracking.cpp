/*
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit. Given a non-negative integer n representing the total number
 * of bits in the code, print the sequence of gray code. A gray code sequence
 * must begin with 0.
 * 
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 *
 * There might be multiple gray code sequences possible for a given n. Return
 * any such sequence.
 *
 * Time complexity: (2^N), where N is the number of bits
 * Explanation:
 * 
 * There are two approaches. The iterative one is easier than the recursive one.
 * 
 * Recursive: call the function two times, one when you are setting the bit in
 * a specific position and other when you are not setting this bit. So, the main
 * thought is: replicate all the bits from your last found number in your first
 * call, then in your second call that bit will change to 0 or 1, then you
 * replicate again. Each time you are setting a bit you need a variable to keep
 * your current value and a variable to keep your current power (bit position).
 * Example:
 * For n = 2, start with the bits 00:
 * 0 0 initially in our vector
 * 
 * 0 0 we replicate until we reach the end and start to return
 * 
 * 0 1 change one bit, and we are at the end of our positions so we return
 * 
 * 1 1 change the bit at the position pointed by the function call we just
 *     returned and replicate until we reach the end and start to return again
 * 
 * 1 0 change one bit, and we are at the end of our positions so we return
 * 
 * Iterative:
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void _grayCode(int curr, int power, vector<int> &ans) {
  if (power == 0) {
    ans.push_back(curr);
    return;
  }

  if ((ans.back() & (1 << (power - 1))) != 0) {
    _grayCode(curr + (1 << (power - 1)), power - 1, ans);
    _grayCode(curr, power - 1, ans);
  }
  else {
    _grayCode(curr, power - 1, ans);
    _grayCode(curr + (1 << (power - 1)), power - 1, ans);
  }
}

vector<int> grayCode(int a) {
  vector<int> ans;

  if (a == 0) return ans;
  ans.push_back(0);

  _grayCode(0, a, ans);
  ans.erase(ans.begin());

  return ans;
}

// vector<int> grayCode(int n) {
//   vector<int> result(1, 0);        
//   for (int i = 0; i < n; i++) {
//     int curSize = result.size();
//     // push back all element in result in reverse order
//     for (int j = curSize - 1; j >= 0; j--) {
//       result.push_back(result[j] + (1 << i));
//     } 
//   }
//   return result;
// }

int main() {
  int a;
  cout << "Type the number of bits: ";
  cin >> a;
  cout << '\n';
  vector<int> r = grayCode(a);

  cout << "Answer has " << r.size() << " elements:" << '\n';
  cout << "[ ";
  for (int j = 0; j < r.size(); j++) {
    cout << r[j] << ' ';
  }
  cout << "]" << '\n';

  // cout << "Checking answer:\n";
  // for (int j = 1; j < r.size(); j++) {
  //   cout << ((r[j] ^ r[j - 1]) & ((r[j] ^ r[j - 1]) - 1)) << ' ';
  // }
  // cout << '\n';

  return 0;
}