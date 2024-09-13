
// Sort + to_string method used 
class Solution {
public:
    bool isFascinating(int n) {
        string str = to_string(n) + to_string(n*2) + to_string(n*3);
        sort(str.begin(),str.end());
        if(str == "123456789"){
            return true;
        }
        return false;
    }
};