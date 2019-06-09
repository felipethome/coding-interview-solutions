/**
 * Given a number N, return number of ways you can draw N chords in a circle
 * with 2*N points such that no 2 chords intersect. Two ways are different if
 * there exists a chord which is present in one way and not in other.
 * Return answer modulo 109+7.
 * 
 * Example:
 * N = 2
 * If points are numbered 1 to 4 in clockwise direction, then different ways to
 * draw chords are: {(1-2), (3-4)} and {(1-4), (2-3)}
 *
 * So, we return 2.
 * 
 * Note 1: 1 ≤ N ≤ 1000
 *
 * Time complexity: O(N^2), where N is the number of chords.
 * Space complexity: O(N).
 *
 * Explanation: the way I did this exercise maybe is not the simplest one, but
 * once you get it, it is easy. The first thing I realized was that if we
 * enumerate the cords in increasing order and in clockwise orientation
 * the chord that has 1 as its beginning point will be connected to all even
 * numbers after it. It needs to be even numbers because we need to have a even
 * amount of points between the chord we connect to be sure these points in
 * between  that are left can all be connected. For example, 1 -> 4, left us
 * with 2 and 3, so they can be connected. 1 -> 6, left us with 2, 3, 4, and 5
 * so they can be connected. Notice, that now we know one chord that will be
 * present in each possible combination. For example, if N is 3 so we know that
 * in each group we gonna have one of the following chords 1 -> 2, 1 -> 4 or
 * 1 -> 6, since we need to connect all points. So, what we need to figure it
 * out is how many combinations we can do with the points we are left with when
 * we connect 1 -> 2 or 1 -> 4, 1 -> 6, etc. That is where we use DP. If we know
 * the base case that is 1 (when we have N = 1) we can find the others. For
 * example, in N = 2 we have 4 points (1, 2, 3, 4). If we connect 1 -> 2, we
 * are left with 3 and 4, since they are just two points they can just be
 * connected in one way. If we connect 1 -> 4, we are left with 2 and 3 and
 * again they can just be connected in one way. This give us for N = 2, 2
 * possible combinations. Now, lets look at N = 3:
 *
 * 1 -> 2, left with 3, 4, 5, 6. They are 4 points and from our previous
 * calculation we already know that for 4 points we have 2 possible
 * combinations.
 *
 * 1 -> 4, left with 2, 3 | 5, 6. This "|" symbol is used to indicate I have
 * a point being used in the middle that is 4. So we need to look at 2 and 3
 * separately to 5 and 6. 2 and 3 = 1 combination, 5 and 6 = 1 combination. So,
 * we have 1 * 1 = 1 (Note the multiplication here).
 *
 * 1 -> 6, left with 2, 3, 4, 5. They are four points so we know we can make
 * 2 combinations.
 *
 * Summing up: 2 + 1 + 2 = 5. And we keep doing this until we calculated our N.
 * Notice, that when we have groups that need to be looked separately like above
 * (2, 3 | 5, 6) we need to multiply the numbers we get to have the correct
 * result of combinations of that iteration.
 *
 * Notice too our answers for different N's will be:
 * N = 1, 1
 * N = 2, 2
 * N = 3, 5
 * N = 4, 14
 * N = 5, 42
 * I'm pointing that out because there are another DP exercises where you will
 * find the answers being these numbers and all of them can be solved in the
 * same way.
 */

#include <iostream>
#include <vector>

using namespace std;

int chordCnt(int n) {
  vector<int> counts;
  counts.push_back(0);
  counts.push_back(1);

  for (int i = 2; i <= n; i++) {
    int chordCount = 0;
    long long left = 1, right = 1;
    for (int j = 2; j <= 2 * i; j += 2) {
      if ((2 * i) - j >= 2) {
        left = counts[((2 * i) - j) / 2];
      }

      if (j - 2 >= 2) {
        right = counts[(j - 2) / 2];
      }

      chordCount = (chordCount + ((left * right) % 1000000007)) % 1000000007;
    }
    counts.push_back(chordCount);
  }

  return counts.back();
}

int main() {
  int a;

  cout << "N: ";
  cin >> a;
  cout << endl;

  int m = chordCnt(a);

  cout << "max: " << m << endl;

  return 0;
}