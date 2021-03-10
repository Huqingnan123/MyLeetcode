class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int oldNum = x;
        int result = 0;
        while(x != 0) {
            int last = x % 10;
            x /= 10;
            if(result > INT_MAX/10 || (result == INT_MAX/10 && last > 7))
                return false;
            result = result * 10 + last;
        }
        return result == oldNum;
    }
};