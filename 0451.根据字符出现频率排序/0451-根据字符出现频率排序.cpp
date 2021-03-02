class Solution {
public:
    string frequencySort(string s) {
        // ���ȶԸ��ַ����м���
        unordered_map<char, int> countMap;
        for(auto ch : s)
            countMap[ch]++;
        // �����ַ����ֵĴ�����Ϊfirst��Ա�����ַ���Ϊsecond��Ա���γ�pair�������ȶ�����(���ճ���Ƶ�ʴӴ�С��������)
        priority_queue<pair<int, char>> q;
        for(auto it = countMap.begin(); it != countMap.end(); it++)
            q.push(make_pair(it->second, it->first));
        string result;
        while(!q.empty())
        {
            //�γ�һ��temp�ַ�����һ���ַ��ĳ��ִ����Լ����ַ���ֵ����ͬ�ַ������һ��
            string temp(q.top().first, q.top().second);
            result.append(temp);
            q.pop();
        }
        return result;
    }
};