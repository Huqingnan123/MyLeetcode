class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0;
        int maxlen = 0;
        while(right < s.size()) {
            char c = s[right++];
            window[c]++;
            while(window[c] == 2) {
                char d = s[left++];
                window[d]--;
            }
            maxlen = max(right - left, maxlen);
        }
        return maxlen;
    }
};