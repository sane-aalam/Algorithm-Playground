

// * Indentification of problem statmenet
// *  first revese the innner most () brakets
// * When i seen any questons about {barkets()[]}, firstly i think About stack
// * Question - Can i use stack? 
// * answer - Yes!

// 1. Open bracket = push into the stack
// 2. close bracket = pop into the stack
// 3.    but remember, when you are poping the element, no need revese the string (currentstring) 
// 4.    stack follow lifo apppaoch,while poping the char automatically reverse the inner bracket
// 5.  Last point - make sure remove "open brack (" into the stack
// 6.  push again currentString into the stack, revese the full stack

// 1. do one dry run
// 2. 2 dry run i have done!
// 3. i can write code easy


class Solution {
public:
    string reverseParentheses(string s) {

        std::stack<char> st;
        for (int i = 0; i < s.length(); i++) {
             char c = s[i];

            if(c == ')'){
                string reverseString = "";
                while(!st.empty() and st.top() != '('){
                    reverseString += st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                    // pop the oping bracket (extra) into the st
                }
            // push again remenaing string into the stack for perfrom future brackets
                // for (int j = 0; j < reverseString.length(); j++) {
                //     st.push(reverseString[j]);
                // }

                for(auto it : reverseString){
                    st.push(it);
                }
            }else{
                st.push(c);
            }
        }

        string result = "";
    
        while(!st.empty()){
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};