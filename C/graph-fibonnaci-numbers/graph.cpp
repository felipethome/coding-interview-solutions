/**
 * What is the minimum amount of Fibonacci numbers required so their sum is
 * equal to a given Number N? N is a positive number.
 * 
 * Note: repetition of number is allowed.
 * 
 * Example:
 * 
 * N = 4
 * Fibonacci numbers : 1 1 2 3 5 .... so on
 * here 2 + 2 = 4, so minimum numbers will be 2
 *
 * Time complexity: O(NlogN), where N is is the given number and logN comes from
 * the fact that there are logN Fibonacci numbers smaller than N. This
 * complexity is for the greedy approach.
 * Space complexity: O(logN).
 *
 * Explanation: "shortest path", "dynamic programming coin changing", "greedy",
 * are all possible approaches for this problem.
 * 
 * This exercise is based on Zeckendorf's Theorem that states that every
 * positive integer larger than 2 can be represented as the sum of
 * non-neighbor Fibonacci numbers. From this theorem we can deduce that if we
 * get the largest Fibonacci number smaller or equal to N (call it fib(i)),
 * then N - fib(i) will have its own representation as a sum of Fibonacci
 * numbers. As we are always getting the largest possible ones, the amount of
 * numbers will be minimum. Also, notice that we will never use Fibonacci
 * neighbors because if we use fib(i) and fib(i - 1) we could use instead
 * fib(i + 1), so actually fib(i + 1) would be the largest number smaller or
 * equal to N.
 *
 * For the shortest path approach you need to build a graph where the vertices
 * are all the numbers 0 .. N. The edges will all have weight 1 and they will
 * connect a number u to all the possible numbers v that you can get subtracting
 * from u a Fibonacci number. After, you get the shortest path from N to 0. The
 * time and space complexity is this case would be O(N^2)
 */

#include <iostream>
#include <vector>
#include <queue>

#define INF 999999

using namespace std;

vector<int> fib(int n) {
  vector<int> ans;
  int f1 = 1, f2 = 1;
  ans.push_back(1);

  while (f1 + f2 <= n) {
    ans.push_back(f1 + f2);
    int temp = f1;
    f1 = f2;
    f2 = temp + f2;
  }

  return ans;
}

int getLargestFib(vector<int> &f, int n) {
  int prev = 0;

  for (int i = 0; i < f.size(); i++) {
    if (f[i] > n) return f[prev];
    else prev = i;
  }

  return f[prev];
}

int fibsum(int n) {
  if (n == 1 || n == 2) return 1;

  vector<int> f = fib(n);
  int ans = 0;

  while (n > 0) {
    int larger = getLargestFib(f, n);
    n = n - larger;
    ans++;
  }

  return ans;
}

/* --- Shortest Path approach --- */
// vector<int> fib(int n) {
//   vector<int> ans;
//   if (n == 0) return ans;

//   int f1 = 1, f2 = 1;
//   ans.push_back(1);

//   while (f1 + f2 <= n) {
//     ans.push_back(f1 + f2);
//     int temp = f1;
//     f1 = f2;
//     f2 = temp + f2;
//   }

//   return ans;
// }

// int getLargestFibIndex(vector<int> &f, int n) {
//   int prev = -1;

//   for (int i = 0; i < f.size(); i++) {
//     if (f[i] > n) return prev;
//     else prev = i;
//   }

//   return prev;
// }

// int shortestPath(vector<vector<int>> &g, int src, int dest) {
//   int n = g.size();
//   queue<int> q;
//   vector<bool>visited(n, false);
//   vector<int> dist(n, INF);

//   q.push(src);
//   visited[src] = true;
//   dist[src] = 0;

//   while (!q.empty()) {
//     int curr = q.front();
//     q.pop();

//     if (curr == dest) return dist[dest];

//     for (int i = 0; i < g[curr].size(); i++) {
//       int v = g[curr][i];
//       if (!visited[v]) {
//         dist[v] = min(dist[v], dist[curr] + 1);
//         visited[v] = true;
//         q.push(v);
//       }
//     }
//   }

//   return dist[dest];
// }

// int minFibNumbers(int n) {
//   vector<vector<int>> g(n + 1, vector<int>());
//   vector<int> f = fib(n);

//   for (int i = 1; i <= n; i++) {
//     for (int j = getLargestFibIndex(f, i); j >= 0; j--) {
//       g[i].push_back(i - f[j]);
//     }
//   }

//   return shortestPath(g, n, 0);
// }

int main() {
  // int a = 1;
  // int a = 2;
  // int a = 4;
  // int a = 5;
  // int a = 30;
  // int a = 10234;
  int a = 1401203453;

  int r = fibsum(a);

  cout << "m: " << r << endl;

  return 0;
}