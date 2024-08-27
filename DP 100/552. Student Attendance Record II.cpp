/*

An attendance record for a student can be represented as a string where each character 
signifies whether the student was absent, late, or present on that day. 
The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n
that make a student eligible for an attendance award. The answer may be very large, so return it modulo 109 + 7.
 */

class Solution {
public:
    int M = 1e9+7;
    int t[100001][2][3];

    int solve(int n, int absent, int consecutive_late) {

        if(absent >= 2 || consecutive_late >= 3) {
            return 0;
        }

        if(n == 0)
            return 1;
        
        if(t[n][absent][consecutive_late] != -1) {
            return t[n][absent][consecutive_late];
        }

        // you have three choice
        // choice-1 you can absent the class
        // choice-2 you can late into the class
        // case-3 you can last present (doing greate)
        int A = solve(n-1, absent+1, 0) % M;
        int L = solve(n-1, absent, consecutive_late+1) % M;
        int P = solve(n-1, absent, 0) % M;

        return t[n][absent][consecutive_late] = ((A + L) % M + P) % M;
    }
public:
    int checkRecord(int n) {
        memset(t,-1,sizeof(t));
        return solve(n,0,0);
;    }
};