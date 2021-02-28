class Solution {
public:
    int longestSubstring(string s, int k) {
        int result = 0;
        //total代表着窗口内最多可以存在的字符种类数量
        for(int total = 1; total <= 26; total++)
        {
            // s仅由小写字母a~z组成
            int windows[26]{0};
            int left = 0, right = 0;
            // count代表窗口内的字符种类数量，illegal代表窗口内数量 < k的不合法字符数量（快速判断当前字符串是否合法）
            int count = 0, illegal = 0;
            int maxlen = 0;
            while(right < s.size())
            {
                char c = s[right];
                right++;
                windows[c - 'a']++;
                if(windows[c - 'a'] == 1)
                {
                    illegal++;
                    count++;
                }
                if(windows[c - 'a'] == k)
                    illegal--;
                // 当窗口内的字符数量比预定total要大时，左移窗口进行收缩
                while(count > total)
                {
                    char d = s[left];
                    left++;
                    windows[d - 'a']--;
                    if(windows[d - 'a'] == 0)
                    {
                        count--;
                        illegal--;
                    }
                    if(windows[d - 'a'] == k-1)
                        illegal++;
                }
                if(illegal == 0)
                    maxlen = max(maxlen, right - left);
            }
            result = max(result, maxlen);
        }
        return result;
    }
};