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
            //��ǰ�ַ��ظ�֮��һֱleft����ֱ��ȥ���ظ���ĸ
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