class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> windows;
        unordered_map<char, int> need;
        for(auto ch : s1)
            need[ch]++;
        int left = 0, right = 0;
        int valid = 0;
        while(right < s2.size()) {
            char c = s2[right];
            right++;
            if(need.count(c) != 0) {
                windows[c]++;
                if(windows[c] == need[c])
                    valid++;
            }
            while(right - left > s1.size()) {
                char d = s2[left];
                left++;
                if(need.count(d) != 0) {
                    windows[d]--;
                    if(windows[d] == need[d] - 1)
                        valid--;
                }
            } 
            if(valid == need.size())
                return true;
        }
        return false;
    }
};