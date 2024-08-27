class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort STL simple + clear
        // TC - 0(nlog(n))
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};


// phone interview quesitons [mostly asked]
// TC - 0(n)
// Sc - 0(n)

class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char,int> mp;
        
        // store the first [string s] frquency into the map 
        for(auto ch : s){
            mp[ch-'a']++;
        }

        // on the basic of second string, reduce the fequency 
        for(auto ch : t){
            mp[ch-'a']--;
        }
        
        // Check after reducing the frequency of the map, present any char or not
        for(auto it : mp){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};