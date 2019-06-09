/**
 * You are given a sequence of black and white horses, and a set of K stables
 * numbered 1 to K. You have to accommodate the horses into the stables in such
 * a way that the following conditions are satisfied:
 *
 * You fill the horses into the stables preserving the relative order of horses.
 * For instance, you cannot put horse 1 into stable 2 and horse 2 into stable 1.
 * 
 * No stable should be empty and no horse should be left unaccommodated.
 * 
 * Take the product (number of white horses * number of black horses) for each
 * stable and take the sum of all these products. This value should be the
 * minimum among all possible accommodation arrangements.
 *
 * Note: If a solution is not possible, then return -1,
 *
 * Example:
 * Input: {WWWB} , K = 2
 * Output: 0, because we have 3 choices {W, WWB}, {WW, WB}, {WWW, B}
 * for first choice we will get 1*0 + 2*1 = 2,
 * for second choice we will get 2*0 + 1*1 = 1,
 * for third choice we will get 3*0 + 0*1 = 0.
 * Of the 3 choices, the third choice is the best option.
 *
 * Time complexity: O(N * M), where N is the number of horses and M is the
 * number of stables.
 * Space complexity: O(M).
 *
 * Explanation: think about the recursive approach and then use memoization.
 * The recursive approach is to call the function for each stable and then
 * try all the combinations of horses for that stable. The combination is easy,
 * you just need a for loop because we need to maintain the order of the horses
 * (we can't permutate them). So, in our funcition signature we also will
 * need to keep where in our vector of horses we must start at that call. If
 * our first stable is trying to keep for example horses 0 and 1, in our next
 * call/stable we need to start from the horse 2. Basically, we have:
 * for(i = start to the end) arrange(horses, stables - 1, i + 1)
 * Now, if you think a little you will notice that we are repeating a lot of
 * calculations. When we start an iteration from index 2 to 5 and 2 stables,
 * in our next call for 2 stables (that comes from the "for" loop of 3 stables),
 * we gonna iterate from 3 to 5, so we are recalculating the results for horses
 * of indices 3, 4, 5. This would be exponential, but if we memoize we can
 * make this polynomial.
 * 
 */

#include <iostream>
#include <vector>
#include <map>
#include <sys/time.h>
#include <ctime>

using namespace std;

int _arrange(string a, int b, int start, map<pair<int, int>, int> &cache) {
  pair<int, int> key = make_pair(start, b);
  if (cache.find(key) != cache.end()) return cache[key];

  int nb = 0, nw = 0, product, temp, ans = INT_MAX;

  for (int i = start; i < a.size(); i++) {
    if (a[i] == 'W') nw++;
    else if (a[i] == 'B') nb++;
    product = nw * nb;

    if (b > 1 && i + 1 < a.size()) {
      temp = _arrange(a, b - 1, i + 1, cache);
      if (temp < INT_MAX) ans = min(ans, temp + product);
      cache[make_pair(i + 1, b - 1)] = temp;
    }
  }

  if (b == 1) ans = product;

  return ans;
}

int arrange(string a, int b) {
  if (b == 0 || a.size() == 0 || b > a.size()) return -1;

  map<pair<int, int>, int> cache;

  return _arrange(a, b, 0, cache);
}

static uint64_t now() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return ((uint64_t) t.tv_sec) * 1000000 + (uint64_t) t.tv_usec;
}

int main() {
  vector<pair<string, int>> tests;

  tests.push_back(make_pair("", 0)); // -1
  tests.push_back(make_pair("W", 0)); // -1
  tests.push_back(make_pair("WB", 3)); // -1
  tests.push_back(make_pair("WB", 1)); // 1
  tests.push_back(make_pair("WWWB", 2)); // 0
  tests.push_back(make_pair("WWWB", 3)); // 0
  tests.push_back(make_pair("WBWB", 3)); // 1
  tests.push_back(make_pair("WBWBWB", 3)); // 3
  tests.push_back(make_pair("WWWWBWWWWWWBBWB", 3)); // 7
  tests.push_back(make_pair("WWWWBWWWWWWBBWB", 5)); // 1
  tests.push_back(make_pair("BWWWWBBBWWWWBWWBWBBBBWBBWWBBWBWWBBBWBWWBBWWWBBWBBB", 13)); // 27

  for (int i = 0; i < tests.size(); i++) {
    pair<string, int> inputs = tests[i];
    string a = inputs.first;
    int b = inputs.second;

    uint64_t t1 = now();
    int m = arrange(a, b);
    uint64_t t2 = now();

    cout << "min: " << m << " time: " << t2 - t1 << "usec" << endl;
  }

  return 0;
}