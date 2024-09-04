/*
You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
Return the minimum number of deletions needed to make s balanced.*/
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int res = 0, count = 0;
        for (char c : s)
        {
            if (c == 'b')
                count++;
            else if (count)
            {
                res++;
                count--;
            }
        }
        return res;
    }
};