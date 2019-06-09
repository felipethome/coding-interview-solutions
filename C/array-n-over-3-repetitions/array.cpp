/**
 * You’re given a read only array of n integers. Find out if any integer occurs
 * more than n/3 times in the array in linear time and constant additional
 * space. If so, return the integer. If not, return -1.
 * If there are multiple solutions, return any one.

 * Example :
 * 
 * Given [1 2 3 1 1]
 * Output 1, because 1 occurs 3 times which is more than 5/3 times. 
 *
 * Time complexity: O(N), where N is the size of the given array.
 * Space complexity: O(1).
 *
 * Explanation: given k, we want to find out if a number occurs more than n / k
 * times. This is the Boyer-Moore Majority Vote algorithm, but the basic version
 * of this algorithm finds out if a number occur more than n / 2 times. Here,
 * we want n / 3 times, but we will generalize for any integer k.
 *
 * We need to solve this problem k - 1 variables to store information, so if
 * k is small we can say that this algorithm has linear time complexity, and
 * constant space complexity. If k is large we say we have O(n * k) time
 * complexity and O(k) space complexity.
 *
 * Lets see how we would approach this problem for k = 2. We have 1 variable,
 * which is a struct with an integer indicating an element, and another
 * integer indicating the number of repetitions for this element. When k = 2,
 * it is easy to see that the majority element will have a count that you could
 * subtract the sum of counts of every other element and you still would have
 * a number larger than 0. Boyer-Moore look at each element just once and if
 * it already saw this number before (the check is performed using our unique
 * variable that stores an element and its count) the algorithm increments the
 * count, otherwise it has two options:
 *
 * 1. Decrement the count if it is larger than 0.
 * 2. If the count is already 0 store the current element.
 *
 * So, if we have a count of 1 for a particular element, and the current element
 * is different from the one with count 1, we just decrement our count and
 * continue the iteration discarding the current element. The idea is that we
 * are checking if we have more elements different from the one with the count
 * because the majority element will be present at least (n / 2 + 1) times which
 * is larger than the rest of elements (n / 2 - 1).
 *
 * For example,
 * Given [1, 2, 3, 4, 1]
 *
 * #1
 * element = 1 count = 1
 *
 * #2
 * element = 1 count = 0
 *
 * #3
 * element = 3 count = 1
 *
 * #4
 * element = 3 count = 0
 *
 * #5
 * element = 1 count = 1
 *
 * So, we have 1 as a candidate for the majority element. Notice, we have a
 * candidate and not an actual answer because we could have a situation where we
 * were with a count 0 and it happened that we started our count again for the
 * next element giving a count different from 0, but it doesn't mean it is a
 * majority. For example, the array with three elements [1, 2, 3], would give
 * e = 3 and c = 1, but 3 is not a majority. So, after these steps we need to
 * get our variable e and check if it really occurs more than n / 2 times in
 * the array.
 *
 * Now, for k = 3 we need two variables, where each is a struct indicating an
 * element and its count. We are looking for an element that occurs more than
 * n / 3 times. So, we are looking for an element that occurs at least 
 * (n / 3 + 1) times, so the rest of the elements is (2n / 3 - 1). Since we
 * have two variables we have two possible places to store information and
 * we just get rid of one element when its variable has count 0. That means we
 * have the majority as (n / 3 + 1) and there are just ((2n / 3 - 1) / 2) =
 * (n / 3 - 1) elements that can take place in the variable where the majority
 * would be stored. For example,
 *
 * Given [1, 2, 3, 4, 1]
 *
 * #1
 * element1 = 1 count1 = 1
 * element2 = undefined count2 = 0
 *
 * #2
 * element1 = 1 count1 = 1
 * element2 = 2 count2 = 1
 *
 * #3 (decrement both)
 * element1 = 1 count1 = 0
 * element2 = 2 count2 = 0
 *
 * #4
 * element1 = 4 count1 = 1
 * element2 = 2 count2 = 0
 *
 * #5
 * element1 = 4 count1 = 1
 * element2 = 1 count2 = 1
 *
 * Now we check elements 4 and 1 and we find that 1 occurs more than n / 3
 * times.
 *
 * For k = 4, we are looking for an element that occurs at least (n / 4 + 1)
 * times, so the rest of the elements is (3n / 4 - 1). We use three variables
 * so we get (3n / 4 - 1) = (n / 4 - 1). Generalizing this for any integer k,
 * we need k - 1 variables to execute this approach.
 */

#include <iostream>
#include <vector>

using namespace std;

int repeatedNumber(vector<int> &a) {
  int e1 = -1, c1 = 0, e2 = -1, c2 = 0;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] == e1) c1++;
    else if (a[i] == e2) c2++;
    else {
      if (c1 == 0) {
        e1 = a[i];
        c1 = 1;
      }
      else if(c2 == 0) {
        e2 = a[i];
        c2 = 1;
      }
      else {
        c1--;
        c2--;
        if (c1 == 0) e1 = -1;
        if (c2 == 0) e2 = -1;
      }
    }
  }

  int actualC1 = 0, actualC2 = 0;
  for (int i = 0; i < a.size(); i++) {
    if (e1 == a[i]) actualC1++;
    else if (e2 == a[i]) actualC2++;
  }

  if (actualC1 > a.size() / 3) return e1;
  else if (actualC2 > a.size() / 3) return e2;
  else return -1;
}

int main() {
  // vector<int> a = {1};
  // vector<int> a = {1, 2, 3, 4, 5};
  vector<int> a = {1, 2, 3, 1, 1};

  int r = repeatedNumber(a);

  cout << r << endl;

  return 0;
}