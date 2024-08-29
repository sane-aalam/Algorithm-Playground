
/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:-
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 */


// Stack base problem [Algorithm simple]
// TakeUforward atozsheet
// if current char is open bracket hai, Then simply push into the stack
// if current char is closing bracket hai, Then you need checkout the mataching of open bracket
// if(s[index] == '(') and if(s[index] == '{' and s[index] == '[') push into the stack
// otherwise popped the check out the condition 


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int sizeofString = s.size();

        for(int currIndex = 0; currIndex < sizeofString; currIndex++){
            if(s[currIndex] == '(' or s[currIndex] == '{' or s[currIndex] == '['){
                st.push(s[currIndex]);

            }else if(s[currIndex] == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    return false;
                }
            // current char is closing bracket hai
            // top char in the stack is open bracket hai 
            // popped it, right now, valid range!
            }else if(s[currIndex] == '}'){
                if(!st.empty() && st.top() == '{'){
                    st.pop();
                }else{
                    return false;
                }
            }else if(s[currIndex] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        // if you have traversal the complete string
        // Then stack is gonna to empty 
        if(st.size() == 0) return true;
        return false;
    }
};



