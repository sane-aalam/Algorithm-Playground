class Solution {
public:
    string addStrings(string num1, string num2) {
        
        // simple math + carry + bit (%) wala
        // class 1 student wali appraoch hay bhai, kuch naya nahi hai isme 
        
        string ans = "";
        int n = num1.size();
        int m = num2.size();
        int i = n - 1;
        int j = m - 1;
        int carry = 0;

     // Loop until all digits are processed or there is a carry.
        while(i >= 0 || j >= 0 || carry > 0){

            // any case, any number is gonna to empty, we have still num1, num2 remeaing,
            // so have assume zero(0) that number 
            int digit1 = (i>=0) ? num1[i] - '0' : 0;
            int digit2 = (j>=0) ? num2[j] - '0' : 0;

            // sum up kar dia = carry + digit1 + digit2 
            carry += digit1 + digit2;
            int currentDigit = carry % 10;
            // Append the current digit to the result string.
            ans += to_string(currentDigit);
            carry = carry / 10;

            // decease the indexes value
            i--;
            j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};