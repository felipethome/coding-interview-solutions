/*
 * Given an array, find the nearest smaller element G[i] for every element A[i]
 * in the array such that the element has an index smaller than i.
 *
 * More formally,
 * G[i] for an element A[i] is equal an element A[j] such that 
 *   j is maximum possible AND 
 *   j < i AND
 *   A[j] < A[i]
 *
 * Example:
 * Input : A : [4, 5, 2, 10]
 * Return : [-1, 4, -1, 2]
 *
 * Time complexity:
 *
 * Explanation: use a stack to keep candidates. Start to iterate over the array.
 * If the stack is empty there are no candidates so just add -1 to your answer.
 * While the stack is not empty try to find an element in the stack that is
 * smaller than your current element. If you find, add this element to your
 * answer. At the end of each iteration add the current element to the stack.
 *
 * This approach is possible because if an element in the stack is bigger than
 * the current element you are analysing, so this element in the stack is
 * definetely not a better candidate than your current one for the next
 * iteration, so you can remove it.
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> prevSmaller(vector<int> &a) {
  vector<int> r;
  stack<int> s;
  
  for (int i = 0; i < a.size(); i++) {
    while (s.size()) {
      if (s.top() < a[i])  {
        r.push_back(s.top());
        break;
      }
      s.pop();
    }

    if (s.empty()) r.push_back(-1);
    s.push(a[i]);
  }
  
  return r;
}

int main() {
  vector<int> a = {1, 5, 2, 10};
  
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << ' ';
  }

  cout << '\n';

  vector<int> r = prevSmaller(a);

  for (int i = 0; i < r.size(); i++) {
    cout << r[i] << ' ';
  }

  cout << '\n';

  return 0;
}