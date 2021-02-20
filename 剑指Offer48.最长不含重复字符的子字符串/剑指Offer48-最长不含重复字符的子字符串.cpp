class Solution {
public:
    // �������ڿ���window��û���ظ��ַ�
    int lengthOfLongestSubstring(string s) {
        int count[128]{0};
        int left = 0, right = 0;
        int maxlen = 0;
        while(right < s.size())
        {
            count[s[right]]++;
            right++;
            while(count[s[right-1]] != 1)
            {
                count[s[left]]--;
                left++;
            }
            maxlen = max(maxlen, right - left);
        }
        return maxlen;
    }
};