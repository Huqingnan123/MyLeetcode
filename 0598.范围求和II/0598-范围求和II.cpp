class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int row = m;
        int col = n;
        for(auto op : ops) {
            row = min(row, op[0]);
            col = min(col, op[1]);
        }
        return row * col;
    }
};