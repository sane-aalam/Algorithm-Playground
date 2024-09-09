class Solution {
public:
    string losingPlayer(int x, int y) {

        // Alice picks 1 coin with a value of 75 and 4 coins with a value of 10.
        // Why divide by 4;
        // reason 4 coins  with value of 10.
        int qt = y/4;
        int count = 0;
        while(x > 0 && qt > 0){
            count++;
            x--;
            qt--;
        }
         // Alice win (even)
         if(count % 2 == 0)
           return "Bob";
        
        return "Alice";
    }
};