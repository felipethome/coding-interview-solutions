/**
 * Given two binary strings, return their sum (also a binary string).
 * 
 * Example:
 * a = "100"
 * b = "11"
 * Return a + b = “111”.
 *
 * Time complexity: O(N), where N is the length of the string (and if we
 * consider the push_back function of a string object as an O(1) operation).
 *
 * Explanation: iterate from the end of the input strings. Get the integer
 * values from these characters (doing something like character - '0'). Now, you
 * have bit1 and bit2. You also need a "carry" variable. Perform the XOR
 * operation to get the resulting bit from that iteration doing
 * bit1 ^ bit2 ^ carry, and a sum followed by a shift to get the new carry
 * value, (carry + bit1 + bit 2) >> 1. Do that while you still have bits to
 * check in one of your inputs or while carry is equal 1.
 */

#include <iostream>
#include <vector>

using namespace std;

string addBinary(string a, string b) {
  int i = a.size() - 1, j = b.size() - 1, carry = 0;
  string ans = "";
  
  while (i >= 0 || j >= 0 || carry) {
    int b1 = i >= 0 ? a[i] - '0' : 0;
    int b2 = j >= 0 ? b[j] - '0' : 0;

    if (b1 ^ b2 ^ carry) ans.push_back('1');
    else ans.push_back('0');

    carry = (b1 + b2 + carry) >> 1;

    i--;
    j--;
  }
  
  reverse(ans.begin(), ans.end());
  
  return ans;
}


int main() {
  string a = "1100";
  string b = "10011";

  string r = addBinary(a, b);

  cout << a << endl;
  cout << b << endl;
  cout << "Answer: " << r << endl;

  return 0;
}