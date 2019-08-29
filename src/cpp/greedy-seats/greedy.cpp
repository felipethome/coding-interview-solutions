/**
 * There is a row of seats. Assume that it contains N seats adjacent to each
 * other. There is a group of people who are already seated in that row
 * randomly. i.e. some are sitting together & some are scattered. An occupied
 * seat is marked with a character 'x' and an unoccupied seat is marked with a
 * dot ('.').
 * Now your target is to make the whole group sit together i.e. next to each
 * other, without having any vacant seat between them in such a way that the
 * total number of hops or jumps to move them should be minimum.
 * 
 * Return minimum value % MOD where MOD = 10000003.
 *
 * Example:
 * Here is the row having 15 seats represented by the String -
 *              . . . . x . . x x . . . x . .
 * 
 * Now to make them sit together one of approaches is -
 *              . . . . . . x x x x . . . . .
 * 
 * Following are the steps to achieve this -
 * 1. Move the person sitting at 4th index to 6th index -  
 *   Number of jumps by him =   (6 - 4) = 2
 * 
 * 2. Bring the person sitting at 12th index to 9th index - 
 *   Number of jumps by him = (12 - 9) = 3
 * 
 * So now the total number of jumps made = ( 2 + 3 ) % MOD = 5 which is the
 * minimum possible jumps to make them seat together.
 * 
 * There are also other ways to make them sit together but the number of jumps
 * will exceed 5 and that will not be minimum.
 * 
 * For example, bring them all towards the starting of the row i.e. start
 * placing them from index 0. In that case the total number of jumps will be 
 * ( 4 + 6 + 6 + 9 ) % MOD = 25 which is very costly and not an optimized way
 * to do this movement.
 *
 * Time complexity: O(N), where N is the length of the string.
 * Space complexity: O(1).
 *
 * Explanation: my solution is different from the editorial, but I believe it
 * is easier to read and understand. Besides, it has O(1) space complexity.
 * You need to realize three things:
 * 1. the empty seats right at the beginning of a row will never be used,
 * because the cheapest solution will begin at most at the first occupied
 * spot.
 * 2. Once you move a group to the left you will never move this group to the
 * right, because if you move a person 2 seats to the left and then you at
 * some point you move this person 3 seats to the right would be cheapier if
 * you just had left this person where she was. Same thing goes if you move to
 * the right.
 * 3. Now that you know the two facts above, for every group you just need to
 * decide if this group must stay where it is, must go to the left to join the
 * other groups on the left, or must go to the right to joing the other groups
 * on the right.
 *
 * It turns out the decision pointed out on item 3 is easy to make. You just
 * need the total number of people. If the number of people on the left
 * is smaller than the number of people on the right, then you move all people
 * on the left to the right. If the number of people on the left is bigger than
 * the number of people on the right, then you move all people on the right to
 * the left.
 * I will try to explain better what I said above. If you move people that are
 * on the right to the left, you will need to keep moving this group of people
 * to the left in other iterations because of item 2. So, if you have more
 * people in total (with total I mean all people that are on the right, even if
 * there are empty spots between them) on the right you will end up making more
 * movies than you could if you had done the opposite, that is, move people on
 * the left to the right.
 * Another thing, notice that if you have for example 3 empty seats and you are
 * about to move a group of 3 people to the left/right, what you are
 * actually doing is moving everybody to the left/right of "i" to this new
 * spot at 3 seats to the left/right (and not just this group). So, we count the
 * number of empty seats at that iteration, and we decide if we gonna move
 * totalPeopleOnTheLeft to the right, or if we gonna move totalPeopleOnTheRight
 * to the left, and then we add to our answer
 * numberOfEmptySeats * totalPeopleOnTheLeft or
 * numberOfEmptySeats * totalPeopleOnTheRight
 * and reset numberOfEmptySeats to 0, so we can start the count on the next
 * ieration.
 *
 * For example,
 *   Given,                        ...x..xx...x.......xxxx...xx..
 *   Move first group to the right .....xxx...x.......xxxx...xx..
 *   Move first group to the right ........xxxx.......xxxx...xx..
 *   Move first group to the right ...............xxxxxxxx...xx..
 *   Move last group to the left   ...............xxxxxxxxxx.....
 *
 * And an example of the fact that you do not only move a single group, but all
 * the poeple on the left/right of "i",
 *   Given, xxxx....x.x.x
 *   Since your first group has size of 4 we have more people on the left of
 *   "i" (i right now is at index 4, on the "."" right after the last "x" of
 *   this first group). So we need to move people that are on the right side
 *   of "i" to the left. So we get,
 *   xxxxx.x.x....
 *   Notice, how we not just moved the group at index 8, but everybody to the
 *   left. This is important because it makes the implementation much simpler
 *   than trying to do one group at a time.
 */

#include <iostream>

using namespace std;

int seats(string a) {
  int totalPeople = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 'x') totalPeople++;
  }

  int i = 0, peopleOnTheLeft = 0, moves = 0, MOD = 10000003;

  while (a[i] == '.') i++;

  while (i < a.size()) {
    int emptySeats = 0;

    for (; i < a.size() && a[i] == 'x'; i++) peopleOnTheLeft++;
    for (; i < a.size() && a[i] == '.'; i++) emptySeats++;

    int peopleOnTheRight = (totalPeople - peopleOnTheLeft) % MOD;
    peopleOnTheLeft %= MOD;
    emptySeats %= MOD;

    if (peopleOnTheLeft < peopleOnTheRight) {
      moves = (moves + ((emptySeats * peopleOnTheLeft) % MOD)) % MOD;
    }
    else {
      moves = (moves + ((emptySeats * peopleOnTheRight) % MOD)) % MOD;
    }
  }

  return moves;
}

int main() {
  // string a = "";
  // string a = "....x..xx...x..";
  // string a = "...x..........xxx";
  // string a = "xxx..x......xx...x";
  // string a = "xxx..........x.x.x.x";
  string a = "...x..xx...x.......xxxx...xx..";

  int m = seats(a);

  cout << "m: " << m << endl;

  return 0;
}