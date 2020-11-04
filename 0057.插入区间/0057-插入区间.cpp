class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> result;
        //����ԭ����intervals����ÿһ������
        for (auto& interval: intervals) {
            if (interval[0] > right) {
                // ��newInterval������Ҳ����޽���
                if (!placed) {
                    result.push_back({left, right});
                    placed = true;          //���newInterval�Ƿ����result��                   
                }
                result.push_back(interval);
                //һ����ˣ�֮��ȫ�������֧
            }
            else if (interval[1] < left) {
                // ��newInterval�����������޽���
                result.push_back(interval);
            }
            else {
                // ��newInterval�����н���������һ���������ǵĲ����γ�һ���µ�newInterval
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            result.push_back({left, right});
        }
        return result;
    }
};