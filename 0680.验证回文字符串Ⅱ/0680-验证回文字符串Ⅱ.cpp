class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        // 双指针向中间移动
        while(left <= right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            // 删除left或者right所指的字符，再去判断内部剩下的字符串是否回文(仅有一次删除机会)
            else
                return isPalindrome(s,left,right-1) || isPalindrome(s,left+1,right);
        }
        return true;
    }
    bool isPalindrome(string& s, int left, int right) {
        while(left <= right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};