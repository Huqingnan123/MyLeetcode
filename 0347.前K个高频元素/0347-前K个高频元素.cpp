class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // ����ͳ�Ƹ����ֳ��ֵĴ���
        unordered_map<int, int> countMap;
        for(auto num : nums)
            countMap[num]++;
        // �������ֳ��ֵĴ�����Ϊfirst��Ա����������Ϊsecond��Ա���������ȶ��и��ݳ���Ƶ�ʽ��С���������
        priority_queue<pair<int, int>> q;
        for(auto it = countMap.begin(); it != countMap.end(); it++)
            q.push(make_pair(it->second, it->first));
        vector<int> result;
        // ȡ����Ƶ��ǰ k �ߵ�Ԫ��
        for(int i = 0; i < k; i++)
        {
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};