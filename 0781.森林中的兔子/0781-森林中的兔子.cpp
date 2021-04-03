class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> mp;
        for(auto num : answers) {
            if(num == 0) {
                res += 1;
                continue;
            }
            if(mp.find(num) == mp.end()) {
                res += num+1;
                mp[num] = num;
            }
            else if(mp.find(num) != mp.end()) {
                mp[num]--;
                if(mp[num] == 0) {
                    mp.erase(num);
                }
            }
        }
        return res;
    }
};