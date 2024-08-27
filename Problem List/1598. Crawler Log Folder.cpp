class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string> st;
        for(string & log : logs){
            if(log == "../"){
            // make sure- alredy stack is empty or not
               if(!st.empty()){
                 st.pop();
               }
            // skip this condtion, because, we need to do nothing for this './' conditon
            // no operation required!
            }else if(log == "./"){
                continue;
            }else{
                st.push(log);
            }
        }
        return st.size();
    }
};