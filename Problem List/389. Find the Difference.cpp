class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumS = 0;
        for(int i = 0; i<s.size(); i++){
            sumS = sumS + s[i];
        }

        int sumT = 0;
        for(int i =0; i<t.size(); i++){
            sumT = sumT + t[i];
        }

        // consider (e) ASIC Value baki hai
        // Then we need to convert into char 
        return char(sumT - sumS);
    }
};