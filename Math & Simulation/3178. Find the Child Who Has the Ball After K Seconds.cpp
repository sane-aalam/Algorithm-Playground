class Solution {
public:
    int numberOfChild(int n, int k) {

        int time = k;
         // moment of backward move, forward move
        int cycleLength = n - 1;
        int fullCycle = time / cycleLength;
        int remainderTime = time % cycleLength;

        if(fullCycle % 2 == 0){
            // forward jana hai otherwise backward jana 
            return remainderTime;
        }else{
            return n - remainderTime - 1;
        }
    }
};