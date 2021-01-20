class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int maxlen = 0;
        while(right < s.size())
        {
            char c = s[right];
            right++;
            window[c]++;
            //当前字符重复之后，一直left右移直至去除重复字母
            while(window[c] != 1)
            {
                char d = s[left];
                left++;
                window[d]--;
            }
            maxlen = max(maxlen, right - left);
        }
        return maxlen;
    }     
};