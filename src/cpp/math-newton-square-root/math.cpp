/**
 * Newton method applied to calculate square roots.
 */

#include <iostream>
#include <cmath>

using namespace std;

int c = 0;

double nSqrt(double a, double guess) {
  if (a == 0) return 0;
  if (a == 1) return 1;

  double ans = guess, prevAns;
  double threshold = 0.001;

  do {
    c++;
    prevAns = ans;
    ans = 0.5 * (prevAns + (a / prevAns));
  } while (abs(ans - prevAns) > threshold);

  return ans;
}

int main() {
  double a, guess, x;

  cout << "Type the number you want to get the square root: ";
  cin >> a;
  cout << endl;

  cout << "Type your guess: ";
  cin >> guess;
  cout << endl;

  x = nSqrt(a, guess);

  cout << "Square root of " << a << ": " << x << endl;
  cout << "Number of iterations: " << c << endl;

  return 0;
}