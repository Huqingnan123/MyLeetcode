class Solution {
public:
    int longestSubstring(string s, int k) {
        int result = 0;
        //total�����Ŵ����������Դ��ڵ��ַ���������
        for(int total = 1; total <= 26; total++)
        {
            // s����Сд��ĸa~z���
            int windows[26]{0};
            int left = 0, right = 0;
            // count�������ڵ��ַ�����������illegal������������ < k�Ĳ��Ϸ��ַ������������жϵ�ǰ�ַ����Ƿ�Ϸ���
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
                // �������ڵ��ַ�������Ԥ��totalҪ��ʱ�����ƴ��ڽ�������
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