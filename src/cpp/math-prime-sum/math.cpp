/**
 * Given an even number ( greater than 2 ), return two prime numbers whose sum
 * will be equal to given number.
 * 
 * Note 1: A solution will always exist. read Goldbach’s conjecture
 * Note 2: If there are more than one solutions possible, return the
 * lexicographically smaller solution.
 * 
 * Example:
 * Given 4, return [2, 2], since 2 + 2 = 4.
 *
 * Time complexity: O(N * time complexity of isPrime()). If you use Sieve of
 * Eratosthenes will be O(N * log(log(N))). If you use a simple method will be
 * O(N * sqrt(N)).
 * Space complexity: O(N), if you use Sieve of Eratosthenes, O(1) if you use
 * the common method.
 *
 * Explanation: iterate from 2 to N. Check if the number i is prime and if it
 * is check if (N - i) is also prime, and if it is return [i, N - i].
 *
 * Observation: Check find-prime-numbers-up-to-n problem to see Sieve of
 * Eratosthenes.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int isPrime(int n) {
  if (n < 2) return 0;

  int upperLimit = (int)(sqrt(n));
  for (int i = 2; i <= upperLimit; i++) {
    if (i < n && n % i == 0) return 0;
  }

  return 1;
}

vector<int> primesum(int a) {
  vector<int> ans;

  for (int i = 2; i <= a; i++) {
    if (isPrime(i) && isPrime(a - i)) {
      ans.push_back(i);
      ans.push_back(a - i);
      return ans;
    }
  }

  return ans;
}

int main() {
  for (int i = 4; i <= 100; i += 2) {
    vector<int> r = primesum(i);
    cout << r[0] << " " << r[1] << endl;
  }

  return 0;
}