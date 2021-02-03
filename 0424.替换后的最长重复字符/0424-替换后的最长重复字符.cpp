class Solution {
public:
    int characterReplacement(string s, int k) {
        //记录滑动窗口中各字符的数目(26个大写字母)
        vector<int> windows(26);
        int left = 0, right = 0;
        //maxlen记录最长答案，maxcount记录当前窗口中同一字符出现的最大次数
        int maxlen = 0;
        int maxcount = 0;
        while(right < s.size())
        {
            char c = s[right++];
            windows[c - 'A']++;
            maxcount = max(maxcount, windows[c - 'A']);
            //此时字符串不合法（k次替换不够），窗口需要收缩
            while(right - left - maxcount > k)
            {
                char d = s[left++];
                windows[d - 'A']--;
            }
            maxlen = max(maxlen, right - left);
        }
        return maxlen;
    }
};