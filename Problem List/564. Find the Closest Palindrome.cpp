class Solution {
public:
    // abcde -> abcba, abde -> abba
    long long convert(long long& num) {

        // convert into the string 
        string s = to_string(num);
        // length of string
        int n = s.length();

        // string half karke 
        // last se insert kar do 
        int l = (n - 1) / 2;
        int r = n / 2;

        while (l >= 0) 
               s[r++] = s[l--];

        // convert into the number long long 
        return stoll(s);
    }

    // find the maximum closet number into the string 
    // using binary search 
    long long maxBinarySearch(long long num) {
        long long left = 0, right = num;
        long long ans = INT_MIN;
        while (left <= right) {
            long long mid = (right - left) / 2 + left;
            long long palin = convert(mid);
            if (palin < num) {
                ans = palin;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    // find the min closet number
    // using binary search 
    long long minBinarySearch(long long num) {
        long long left = num, right = 1e18;
        long long ans = INT_MIN;
        while (left <= right) {
            long long mid = (right - left) / 2 + left;
            long long palin = convert(mid);
            if (palin > num) {
                ans = palin;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);

        // 1. convert into long long
        // 2. find out left closest palindromic value
        // 3  find out right closet palindromic value
        // 4. Which one have -> the absolute difference minimized between two integers.
        // 5. simple Binary search algorithm called 
        long long a = maxBinarySearch(num);
        long long b = minBinarySearch(num);
        if (abs(a - num) <= abs(b - num)) return to_string(a);
        return to_string(b);
    }
};