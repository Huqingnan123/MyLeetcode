class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 首先统计各数字出现的次数
        unordered_map<int, int> countMap;
        for(auto num : nums)
            countMap[num]++;
        // 将各数字出现的次数作为first成员，该数字作为second成员，便于优先队列根据出现频率进行“降序”排序
        priority_queue<pair<int, int>> q;
        for(auto it = countMap.begin(); it != countMap.end(); it++)
            q.push(make_pair(it->second, it->first));
        vector<int> result;
        // 取出现频率前 k 高的元素
        for(int i = 0; i < k; i++)
        {
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};