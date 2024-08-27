class Solution {
public:
    int secondHighest(string s) {
        
        int firstDigit = -1;
        int secondDigit = -1;

        for(auto ch : s){
        // to check char is digit 
        // secondDigit and firstDigit student appraoch apply here!
        // AtoZ Sheet [array-1] easy concpet used here 
           if(isdigit(ch)){
            int number = ch - '0';
            if(number > 1 or number < 10){
                 if(number > firstDigit){
                    secondDigit = firstDigit;
                    firstDigit = number;
                 }else if(number < firstDigit && number > secondDigit){
                    secondDigit = number;
                 }
              }
           }
        }
        return secondDigit;
    }
};