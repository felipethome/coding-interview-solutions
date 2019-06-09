#include <iostream>

using namespace std;

int isPrime(int n) {
  if (n < 2) return 0;

  int upperLimit = (int)(sqrt(n));
  for (int i = 2; i <= upperLimit; i++) {
    if (i < n && n % i == 0) return 0;
  }

  return 1;
}

int main() {
  int a = 25;

  bool r = isPrime(a);

  if (r) cout << "Is prime." << endl;
  cout << "Is not a prime." << endl;

  return 0;
}