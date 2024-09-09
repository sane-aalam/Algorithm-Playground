
// Algorithm (Think)
// You can only delete the char, if Frequency of char is more than 3 
// not possible to delete the char, if frequency of char is less than (a-2) < 3
// consider - "aaa" = after deleting the left most + right most = 'a' only 1 remainning
// consider - "aaaa" = after deleting the left most + right most = 'aa' only 2 remaining 
// if even = 2
// if odd = 1 

class Solution {
public:
    int minimumLength(string s) {
    
    // declaration of map (DSA)
        map<char,int> mp;

    // map[char,intger(how many times element came into the string)]
    // store the frequency of each char element into the strings
        for(auto it : s){
            mp[it]++;
        }

    // he minimum length of the final string s that you can achieve.
    // after the removing the char
        int result = 0;
        for(auto it : mp){
            int Fquency = it.second;
            if(Fquency < 3){
                result += Fquency;
            // if frequency more than 3 
            // than it can be even, or odd 
            // on the basic of odd,even we have to remove the left most + right most 
            }else if(Fquency % 2 == 0){
                result += 2;
            }else if(Fquency % 2 == 1){
                result += 1;
            }
        }
        return result;
    }
};