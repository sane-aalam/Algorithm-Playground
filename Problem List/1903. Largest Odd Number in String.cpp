
// Check from the rear end if the digit is odd or not. And we are done.
// "35427" = '7' rear end odd digit so answer (0,lastindex tak)
// Return the substring from start to that digit index.
// Else return ann empty string.

class Solution {
public:
    string largestOddNumber(string num) {
         for(int i = num.size()-1; i >= 0; i--)
        {
            // char to ascii conversion by subtraction 48 (ASCII of 0)
            if((int)(num[i] - 48) % 2 != 0)
            {
                // here return i+1 as the last index is excluded while using the substr function
                // substr can generate the string (0, i+1) tak 
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};