class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int hayLen = haystack.size();
        int needLen = needle.size();
        int total = hayLen - needLen;

        // substr is c++ funciton is used to, just like javascript slice method

        for(int i = 0; i<= total; i++){
            // substring of first string is equal to second string the we can just need to return index value
            // first string [0, needle.size() == "leetcode"] which is equal to "leetcode"
            // return 1
            if(haystack.substr(i,needLen) == needle){
                return i;
            }
        }
        return -1;
    }
};