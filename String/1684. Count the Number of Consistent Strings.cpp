//The problem you're tackling is to count how many strings in a list (words) consist only of characters from a given string (allowed). Let's break down the approach step by step, including the intuition behind it.
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // store each char is set [string allowed]
        set<char> ans;
        for(auto it : allowed){
            ans.insert(it);
        }

        int count = 0;
        for(int i = 0; i<words.size(); i++){
               bool flag = true;
               // Explore each string char one by one 
                for(auto currentChar : words[i]){
                    if(ans.find(currentChar) == ans.end()){
                        flag = false;
                        break;
                    }
                }
                if(flag == true){
                    count++;
                }
        }
        return count;
    }
};