
/*

!You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem. However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.


Input: chalk = [5,1,5], k = 22
Output: 0
Explanation: The students go in turns as follows:
- Student number 0 uses 5 chalk, so k = 17.
- Student number 1 uses 1 chalk, so k = 16.
- Student number 2 uses 5 chalk, so k = 11.
- Student number 0 uses 5 chalk, so k = 6.
- Student number 1 uses 1 chalk, so k = 5.
- Student number 2 uses 5 chalk, so k = 0.
Student number 0 does not have enough chalk, so they will have to replace it.

*/

// Pass the pillow (extension verison problem)
// Math used here + simple simulation of problem

// remainder = k % sum;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
          long long int sum = 0;
          for(auto it : chalk){
             sum += it;
          }

          int remainder = k % sum;
          int n = chalk.size();

          for(int i = 0; i<n; i++){
            // arr[i] value is greater ho jaye at anypoint
            // return i index value
            if(chalk[i] > remainder){
                return i;
            }
            remainder = remainder - chalk[i];
          }
          return -1;
    }
};