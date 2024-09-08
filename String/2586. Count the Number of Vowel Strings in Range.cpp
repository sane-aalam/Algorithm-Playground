class Solution {
public:
    bool isvowel(char str){
        if(str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u'){
            return 1;
        }
        return 0;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for(int i = left; i<= right; i++){
            int curSize = words[i].size() - 1;
            // start with the vowel
            // end with the vowel
            // count increase by 1 
            if(isvowel(words[i][0]) &&  isvowel(words[i][curSize])){
                count ++;
            }
        }
        return count;
    }
};