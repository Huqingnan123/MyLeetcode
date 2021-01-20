class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for(auto c : p)
            need[c]++;
        int left = 0, right = 0;
        //记录已满足个数要求的字符个数
        int valid = 0;
        vector<int> result;
        while(right < s.size())
        {
            char c = s[right];
            right++;
            if(need.count(c))
            {
                window[c]++;
                if(window[c] == need[c])
                    valid++;
            }
            //判断窗口是否需要被收缩
            while(right - left >= p.size())
            {
                if(valid == need.size())
                    result.push_back(left);
                char d = s[left];
                left++;
                if(need.count(d))
                {
                    if(window[d] == need[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return result;
    }
};