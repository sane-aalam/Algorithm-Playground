
// longest paldinromice subsequence + prefix + subffix which is not matched !

class Solution {
    public String shortestPalindrome(String s) {
        int n = s.length(); 
        String rev = "";
      
       // Construct the reverse of the string
        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            rev = ch + rev;
        }

        for(int i = 0; i<n; i++){
             if(s.substring(0,n-i).equals(rev.substring(i))){
                return rev.substring(0,i) + s;
             }
        }
        return rev + s;
    }
}

// KMP algorithm need to learn to solve string problems