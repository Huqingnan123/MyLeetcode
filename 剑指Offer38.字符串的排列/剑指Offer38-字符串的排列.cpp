class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        //只需要考虑s1的排列，所以计算各字符需要的数量即可
        for(auto c : s1)
            need[c]++;
        //左闭右开的一个滑动窗口
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
            //判断左侧窗口是否需要收缩（窗口达到s1长度就要判断并收缩了）
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