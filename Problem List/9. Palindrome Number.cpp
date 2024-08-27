
// Exaction of digit 

class Solution {
public:
    bool isPalindrome(int x) {

    long int reverse = 0;
    // don't want to modify the orignal number, so temp used to modification of number 
    long int temp = x;
      
    if(temp<0){
        return false;
    }
        
    while (temp != 0) {
        long int lastDigit = temp % 10;
        reverse = (reverse * 10) + lastDigit;
        temp = temp / 10;
    }
    
        if(reverse == x){
            return true;
        }else{
            return false;
        }
    }
};