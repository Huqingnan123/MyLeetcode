class Solution {
public:
    string frequencySort(string s) {
        // 首先对各字符进行计数
        unordered_map<char, int> countMap;
        for(auto ch : s)
            countMap[ch]++;
        // 将各字符出现的次数作为first成员，该字符作为second成员，形成pair插入优先队列中(按照出现频率从大到小降序排列)
        priority_queue<pair<int, char>> q;
        for(auto it = countMap.begin(); it != countMap.end(); it++)
            q.push(make_pair(it->second, it->first));
        string result;
        while(!q.empty())
        {
            //形成一个temp字符串（一个字符的出现次数以及该字符的值，相同字符必须放一起）
            string temp(q.top().first, q.top().second);
            result.append(temp);
            q.pop();
        }
        return result;
    }
};