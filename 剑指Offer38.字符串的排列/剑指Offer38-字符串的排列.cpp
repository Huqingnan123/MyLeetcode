class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        //ֻ��Ҫ����s1�����У����Լ�����ַ���Ҫ����������
        for(auto c : s1)
            need[c]++;
        //����ҿ���һ����������
        int left = 0, right = 0;
        int valid = 0;
        while(right < s2.size())
        {
            char c = s2[right];
            right++;
            if(need.count(c))
            {
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }
            //�ж���ര���Ƿ���Ҫ���������ڴﵽs1���Ⱦ�Ҫ�жϲ������ˣ�
            while(right - left >= s1.size())
            {
                if(valid == need.size())
                    return true;
                char d = s2[left];
                left++;
                if(need.count(d))
                {
                    if(window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
};