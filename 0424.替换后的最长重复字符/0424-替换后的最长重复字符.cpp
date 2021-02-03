class Solution {
public:
    int characterReplacement(string s, int k) {
        //��¼���������и��ַ�����Ŀ(26����д��ĸ)
        vector<int> windows(26);
        int left = 0, right = 0;
        //maxlen��¼��𰸣�maxcount��¼��ǰ������ͬһ�ַ����ֵ�������
        int maxlen = 0;
        int maxcount = 0;
        while(right < s.size())
        {
            char c = s[right++];
            windows[c - 'A']++;
            maxcount = max(maxcount, windows[c - 'A']);
            //��ʱ�ַ������Ϸ���k���滻��������������Ҫ����
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