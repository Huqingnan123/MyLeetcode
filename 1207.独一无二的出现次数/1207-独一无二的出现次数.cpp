class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> st;
        for(auto& num : arr)
            mp[num]++;
        auto it = mp.begin();
        while( it != mp.end())
        {
            if(st.find((*it).second) != st.end())
                return false;
            st.insert((*it).second);
            it++;
        }
        return true;
    }
};