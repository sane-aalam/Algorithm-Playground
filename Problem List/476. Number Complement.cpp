

// Do accoring to the question 
//? For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.

class Solution {
public:
    int findComplement(int num) {
          unsigned int highestBit = 1 << (int)(log2(num));
          // right sift all bits by 1 
          int mask =  (highestBit << 1 ) - 1;
          return mask ^ num;
    }
};