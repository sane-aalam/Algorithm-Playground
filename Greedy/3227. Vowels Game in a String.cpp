
// Alice and Bob are playing a game on a string.
// If any number of vowels present,then alice win 
// if there is no vowels present, then bob win
// (Game Theory) aapna best karna hai 

class Solution {
public:
    bool doesAliceWin(string s) {

        int countVowel = 0;
        for(auto ch : s){
           // The English vowels are: a, e, i, o, and u.
            if(ch == 'a' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'e'){
                countVowel++;
            }
        }

        // if(countVowel >= 1){
        //     return true;
        // }else{
        //     return false;
        // }
        // return countVowel >= 1;
        return countVowel;
    }
};