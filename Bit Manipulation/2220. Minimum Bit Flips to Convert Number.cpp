class Solution {
public:

// solution - If the value of a bit in start and goal differ, then we need to flip that bit.

    int minBitFlips(int start, int goal) {
        
        int XOR = start ^ goal;
        int count = 0;
        while(XOR){
            XOR = XOR & (XOR-1);
            count++;
        }
        return count;
    }
};