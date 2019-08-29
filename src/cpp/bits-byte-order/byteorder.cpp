/**
 * Identify the architecture endianess.
 *
 * Time complexity: O(1).
 *
 * Explanation: use a union with 2 bytes. Store in each of these bytes different
 * numbers like 1 and 2. In your union keep an array of chars with two positions
 * so you can read them. If the first byte in this char array is 1 and the
 * second 2 we have a big-endian architecture, little-endian otherwise.
 */

#include <stdio.h>

int main(int argc, char **argv) {
  union {
    short s;
    char c[sizeof(short)];
  } un;
  
  un.s = 0x0102;
  
  if (sizeof(short) == 2) {
    if (un.c[0] == 1 && un.c[1] == 2)printf("big-endian\n");
    
    else if (un.c[0] == 2 && un.c[1] == 1) printf("little-endian\n");
    
    else printf("unknown\n");
  }
  else {
    printf("sizeof(short) = %lu\n", sizeof(short));
  }
  
  return 0;
}