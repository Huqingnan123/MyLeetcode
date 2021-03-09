class Solution {
public:
    // 贪心算法之区间调度问题，最早deadline优先，可以求得最大相容区间子集（互不重叠）
    // 最后需要移除的最小数量就是：原来的size() - 最大相容子集的size()
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //按照终点值(deadline)从小到大排序
        auto cmp = [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];  
        };
        sort(intervals.begin(), intervals.end(), cmp);
        int sum = intervals.size();
        int cur = intervals.size();
        for(int i = 0; i < intervals.size(); i++) {
            int last = intervals[i][1];
            //与上一选择区间的last存在冲突，舍弃
            while(++i < intervals.size() && intervals[i][0] < last) {
                cur--;
            }
            i--;
        }
        return sum - cur;
    }
};