/**
 * Find all primes up to a number N.
 *
 * Example:
 * Given N = 10, return [2, 3, 5, 7]
 *
 * Time complexity: O(N * log(log(N))), where N is the size of the array. The
 * tricky part is to find a sum of primes (2 + 3 + 5 + ...). I believe this
 * is the complexity because the algorithm is similar to Sieve of Eratosthenes.
 * Space complexity: O(N).
 *
 * Explanation: keep a list of primes. Iterate from 2 .. N and keep a list of
 * the primes found so far. For each number i try to divide i by all the primes
 * that you already found. One optimization is:
 * If we have primes = [2, ..., Xi, ...], j = Xi and we are checking a number N
 * bigger than Xi, we already know in our algorithm that N is not multiple of
 * any prime from 2 to Xi-1. So:
 *   1. If Xi is a factor of N, so N / Xi >= Xi.
 *   2. If Xi * Xi > N then N / Xi < Xi, so the above condition is not true,
 *   hence N is prime (because any other prime larger than Xi should respect
 *   the above condition which will not, since Xk > Xi will give a smaller
 *   result for the division).
 *
 * Observation: you can make Sieve of Eratosthenes in O(N) time complexity
 * using more memory. The main idea is to cross each number just once keeping
 * a list of the smallest prime factor of each number up to N.
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> findPrimes(n) {
  vector<int> primes;

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < primes.size(); j++) {
      if (primes[j] * primes[j] > i) {
        primes.push_back(i);
        break;
      }

      if (i % primes[j] == 0) break;
    }

    if (j == primes.size()) primes.push(i);
  }

  return primes;
}

// Sieve of Eratosthenes
vector<int> sieve(n) {
  vector<bool> isPrime(n + 1, true);
  isPrime[0] = false;
  isPrime[1] = false;
  
  for (int i = 2; i <= n; i++) {
    if (!isPrime[i]) continue;
    if (i > n / i) break;
    for (int j = 2 * i; j <= n; j += i) isPrime[j] = false;
  }

  vector<int> primes;
  for (int i = 2; i <= n ; i++) {
    if (isPrime[i]) primes.push_back(i);
  }

  return primes
}

int main() {
  int a = 100;

  vector<int> r = findPrimes(a);

  for (int i = 0; i < findPrimes.size(); i++) {
    cout << r[i] << " ";
  }
  cout << endl;

  return 0;
}