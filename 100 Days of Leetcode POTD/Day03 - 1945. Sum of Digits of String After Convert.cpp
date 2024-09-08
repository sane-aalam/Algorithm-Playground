
/*
You are given a string s consisting of lowercase English letters, and an integer k.
First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). 
Then, transform the integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.

For example, 
if s = "zbax" and k = 2, then the resulting integer would be 8 by the following operations:
    Convert: "zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124
    Transform #1: 262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17
    Transform #2: 17 ➝ 1 + 7 ➝ 8

Return the resulting integer after performing the operations described above. */

// how to convert char 'a' into 1 = currentchar - 'a' + 1 = (intger value 1)
// C++ (Function) (Today i have learnt)
// to_string to convert integer to string value
// stoi("value") to convert string to integer value

class Solution {
public:
    int getLucky(string s, int k) {
        string number = "";
        for(char ch : s){
            int currentNumber = ch - 'a' + 1;
            // push kar do convert kar string me 
            number += to_string(currentNumber);
        }

        // perfrom the transformation k times
        while(k != 0){
            int temp = 0;
            for(char ch : number ){
                // sum of digit 
                temp += ch - '0';
                // char will convert into the ingetger value
            }
            number = to_string(temp);

            // number of transformation can be reduced by 1
            k--;
        }
        return stoi(number);
    }
};