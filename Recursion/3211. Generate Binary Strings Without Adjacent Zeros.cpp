
// you have two choice
// take '0' but not pick the two adjlist consectuive element 'zeros'
// take '1' you can take without condition the consecutive element 'ones'   

class Solution {
private:
   void helper(int index, string curr, int n, vector<string>& GenerateBinaryStrings,bool LastOne){
        
        if(index == n){
            GenerateBinaryStrings.push_back(curr);
            return;
        }
        // pick the 0's + condition (Last alredy 0 na ho)
        // start with 0's index (first 0's insert)
        if(index == 0 or LastOne){
            helper(index+1,curr + '0',n, GenerateBinaryStrings,false);
        }
        // pick the 1's
        helper(index+1,curr+'1',n,GenerateBinaryStrings,true);
   }
public:
    vector<string> validStrings(int n) {
        vector<string> GenerateBinaryStrings;
        int index = 0;
        // to make sure last element is not zero, only one(last)
        bool LastOne = false;
        helper(index,"",n,GenerateBinaryStrings,LastOne);

        // return Generate Binary Strings(all which follow these rules)
        return GenerateBinaryStrings;
    }
};