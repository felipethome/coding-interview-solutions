/**
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format. If the fractional part is repeating,
 * enclose the repeating part in parentheses.
 * 
 * Example:
 * Given numerator = 1, denominator = 2, return "0.5"
 * Given numerator = 2, denominator = 1, return "2"
 * Given numerator = 2, denominator = 3, return "0.(6)"
 *
 * Time complexity: O(N), where N is the total number of digits the number will
 * have.
 *
 * Explanation: calculate digit by digit, where
 * integer part = numerator / denominator and
 * decimals = initialize "rest" with (numerator % denominator) and then perform
 *   (rest * 10) % denominator
 *   rest = rest % denominator
 *   until rest == 0
 * The secret to identify the repeating part is to use a hashmap to store our
 * previously seen "rest's", because when you find a "rest" that you already
 * saw before the calculations (rest / denominator) and (rest % denominator)
 * will start to repeat of course. So, use a hashmap to store your "rest's" and
 * the position where they were first seen (you gonna need this position to
 * insert the opening parenthesis "(" ).
 */

#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

string getDecimals(long long r, long long d) {
  string decimals = "";
  unordered_map<long long, int> st;

  while (r != 0) {
    unordered_map<long long, int>::iterator it = st.find(r);

    // When a number was already seen the digits will start to repeat because
    // when you perform r / d and r % d you will get the same sequence of
    // digits.
    if (it != st.end()) {
      int idx = it->second;
      return (decimals.substr(0, idx) +
        "(" + decimals.substr(idx, decimals.length() - idx) + ")");
    }

    // Remember the current position so we can insert "(".
    st[r] = decimals.length();
    // Get the next digit.
    r *= 10;
    string digit = to_string(r / d);
    decimals += digit;

    r %= d;
  }

  return decimals;
}

string fractionToDecimal(int numerator, int denominator) {
  if (numerator == 0) return "0";

  long long n = numerator;
  long long d = denominator;

  string sign = "";
  if ((n < 0 && d > 0) || (n > 0 && d < 0)) sign = "-";
  n = abs(n);
  d = abs(d);

  string ans = "";
  long long integerPart = n / d;

  ans += to_string(integerPart);

  if (n % d) {
    string decimals = getDecimals(n % d, d);
    if (decimals != "") ans += '.' + decimals;
  }

  return sign + ans;
}

int main() {
  int n, d;

  cout << "Numerator: ";
  cin >> n;
  cout << "Denominator: ";
  cin >> d;
  cout << endl;

  string r = fractionToDecimal(n, d);

  cout << "Answer: " << r << endl;
  
  return 0;
}