/**
 * There are N gas stations along a circular route, where the amount of gas at
 * station i is gas[i]. You have a car with an unlimited gas tank and it costs
 * cost[i] of gas to travel from station i to its next station (i+1). You begin
 * the journey with an empty tank at one of the gas stations.
 *
 * Return the minimum starting gas station’s index if you can travel around
 * the circuit once, otherwise return -1.
 * 
 * Note 1: You can only travel in one direction.
 * i to i + 1, i + 2, ... n - 1, 0, 1..
 * Note 2: Completing the circuit means starting at i and ending up at i again.
 * 
 * Example:
 * Given,
 * Gas: [1, 2]
 * Cost: [2, 1]
 * Output: 1 
 * 
 * If you start from index 0, you can fill in gas[0] = 1 amount of gas. Now your
 * tank has 1 unit of gas. But you need cost[0] = 2 gas to travel to station 1. 
 * If you start from index 1, you can fill in gas[1] = 2 amount of gas. Now your
 * tank has 2 units of gas. You need cost[1] = 1 gas to get to station 0. So,
 * you travel to station 0 and still have 1 unit of gas left over. You fill in
 * gas[0] = 1 unit of additional gas, making your current gas = 2. It costs you
 * cost[0] = 2 to get to station 1, which you do and complete the circuit.
 *
 * Time complexity: O(N), where N is the size of the arrays.
 * Space complexity: O(1).
 *
 * Explanation: think about the fuel tank, while it is positive you can keep
 * adding stations because even if there are negative pumps in your way when
 * you find a positive pump you still would end up with more fuel than if you
 * have started at this just found positive pump (of course, right? because you
 * are adding the left fuel in your tank to this positive number). Now, what
 * happens when you tank becomes negative? Well, this means no pump before this
 * pump that just made your tank negative will be able to complete the trip.
 * So, when your tank becomes negative, just restart it to zero and try to
 * complete the trip from the next pump. In other words, the only possible pumps
 * to fulfill the task are the ones that follow a pump that is making your
 * tank negative.
 */

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  int sumGas = 0, sumCost = 0, start = 0, tank = 0;
  for (int i = 0; i < gas.length; i++) {
    sumGas += gas[i];
    sumCost += cost[i];
    tank += gas[i] - cost[i];
    if (tank < 0) {
      start = i + 1;
      tank = 0;
    }
  }

  return sumGas < sumCost ? -1 : start;
}

// int canCompleteCircuit(const vector<int> &a, const vector<int> &b) {
//   int n = a.size();

//   if (n == 0) return -1;
//   if (n == 1) return 0;

//   int start = -1, tank = 0, i = 0, count = 0;

//   // You need at most 2n executions of this loop to find an answer.
//   while (i != start && count < 2 * n) {
//     tank += (a[i] - b[i]);

//     if (tank < 0) {
//       tank = 0;
//       start = -1;
//     }
//     else if (start == -1) {
//       start = i;
//     }
    
//     i = (i + 1) % n;
//     count++;
//   }

//   return count < 2 * n ? start : -1;
// }

int main() {
  // vector<int> a = {1, 2};
  // vector<int> b = {2, 1};

  // vector<int> a = {2, 3, 5, 1, 8, 4, 6};
  // vector<int> b = {3, 1, 6, 9, 2, 3, 5};
  
  // vector<int> a = {2, 3, 5, 1, 8, 4, 1};
  // vector<int> b = {3, 1, 6, 9, 2, 3, 5};
  
  // vector<int> a = {1, 2, 3};
  // vector<int> b = {2, 1, 1};

  int r = canCompleteCircuit(a, b);

  cout << "min index: " << r << endl;

  return 0;
}