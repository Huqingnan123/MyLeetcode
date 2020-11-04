class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> result;
        //遍历原来的intervals里面每一个区间
        for (auto& interval: intervals) {
            if (interval[0] > right) {
                // 在newInterval区间的右侧且无交集
                if (!placed) {
                    result.push_back({left, right});
                    placed = true;          //标记newInterval是否加入result中                   
                }
                result.push_back(interval);
                //一旦如此，之后全是这个分支
            }
            else if (interval[1] < left) {
                // 在newInterval区间的左侧且无交集
                result.push_back(interval);
            }
            else {
                // 与newInterval区间有交集，二合一，计算它们的并集形成一个新的newInterval
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