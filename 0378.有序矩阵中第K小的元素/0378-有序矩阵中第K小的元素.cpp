class Solution {
public:
    struct Cordinate {
        int x;
        int y;
        int value;
        Cordinate() : x(), y(), value(){}
        Cordinate(int x, int y, int value): x(x), y(y), value(value){}
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 此处cmp函数相当于默认的greater<int>
        auto cmp = [](Cordinate a, Cordinate b){
            return a.value > b.value;
        };
        //q会成为小顶堆，优先队列中元素->升序排列，队首（堆顶）是min元素
        priority_queue<Cordinate, vector<Cordinate>, decltype(cmp)> q(cmp);
        bool hasPushed[matrix.size()][matrix[0].size()];
        memset(hasPushed, false, sizeof(hasPushed));
        q.push(Cordinate(0, 0, matrix[0][0]));
        hasPushed[0][0] = true;
        for(int i = 0; i < k-1; i++) {
            Cordinate poped(q.top().x, q.top().y, q.top().value);
            q.pop();
            if(poped.x + 1 < matrix.size() && hasPushed[poped.x + 1][poped.y] == false)
            {
                q.push(Cordinate(poped.x + 1, poped.y, matrix[poped.x + 1][poped.y]));
                hasPushed[poped.x + 1][poped.y] = true;
            }
                
            if(poped.y + 1 < matrix[0].size() && hasPushed[poped.x][poped.y + 1] == false)
            {
                q.push(Cordinate(poped.x, poped.y + 1, matrix[poped.x][poped.y + 1]));
                hasPushed[poped.x][poped.y + 1] = true;
            }
        }
        return q.top().value;
    }
};