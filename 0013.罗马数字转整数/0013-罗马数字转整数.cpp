class Solution {
public:
    int romanToInt(string s) {
        int num = 0, i = 0;
        map<char, int> mp{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}; 
        if(s.size() == 1)
            return mp[s[0]];
        for(i = 0; i < s.size() - 1; i++)
        {
            int left = mp[s[i]];
            int right = mp[s[i+1]];
            if(left >= right)
                num += left;
            if(left < right)
                num -= left;
        }
        num += mp[s[i]];
        return num;
    }
};