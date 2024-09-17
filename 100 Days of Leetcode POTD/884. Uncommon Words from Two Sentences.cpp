// Combine both sentences into one string.
// Iterate through the combined string to extract individual words, 
// and count their occurrences using a hash map.
// Finally, return all words that occur exactly once.

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        // single string combine 
        string s = s1 + " " + s2 + " ";
        // cout << s << endl; -> this apple is sweet this apple is sour

        unordered_map<string,int> mp;

        // Fequency store into temp
        // Fequency store 2 times aa rahe, 1 times aa rahe toh
        // Iterate through the combined string to extract individual words, 
        // Count it simple 
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                cout<<temp<< endl;
                mp[temp]++;
                temp = "";
            }
            else
            temp+=s[i];
        }

        vector<string> ans;
        for(auto it : mp){
            // jis jis ki fequency only 1 hai 
            // un sab ko answer me store kar lo
            // wo hi uncommon words honge
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};