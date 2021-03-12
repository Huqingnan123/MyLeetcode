class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            int last = result.size()-1;
            //���ص�
            if(intervals[i][0] > result[last][1]) {
                result.push_back(intervals[i]);
            }
            //���ص�������������
            else {  
                result[last][1] = max(result[last][1], intervals[i][1]);
            }
        }
        return result;
    }
};