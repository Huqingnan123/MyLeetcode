class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //自定义cmp函数
        auto my_cmp = [&](vector<int>& a,vector<int>& b) {
            return sqrt(a[0]*a[0] + a[1]*a[1]) <= sqrt(b[0]*b[0] + b[1]*b[1]);
        };
        sort(points.begin(),points.end(),my_cmp);
        //resize只保留K个距离最近的点
        points.resize(K);   
        return points;
    }
};