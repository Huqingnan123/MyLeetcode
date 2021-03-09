class Solution {
public:
    // ̰���㷨֮����������⣬����deadline���ȣ��������������������Ӽ��������ص���
    // �����Ҫ�Ƴ�����С�������ǣ�ԭ����size() - ��������Ӽ���size()
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //�����յ�ֵ(deadline)��С��������
        auto cmp = [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];  
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int sum = intervals.size();
        int cur = intervals.size();
        for(int i = 0; i < intervals.size(); i++) {
            int last = intervals[i][1];
            //����һѡ�������last���ڳ�ͻ������
            while(++i < intervals.size() && intervals[i][0] < last) {
                cur--;
            }
            i--;
        }
        return sum - cur;
    }
};