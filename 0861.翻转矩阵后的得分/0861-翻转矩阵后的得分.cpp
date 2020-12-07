class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        //贪心
        //对于每一行，首位是0可以立即转换
        int line_sum = 0;
        for(auto& line : A)
        {
            line_sum++;
            if(line[0] == 0)     
                for(auto& num : line)
                    num ^= 1;
        }
        //对于每一列，1的个数比0多可以立即转换
        for(int i = 0; i < A[0].size();i++)
        {
            int count = 0;
            for(auto& line : A)
                if(line[i] == 1)
                    count++;
            if(count <= line_sum/2)
            {
                for(auto& line : A)
                    line[i] ^= 1;
            }
        }
        //计算和
        int sum = 0;
        for(auto& line : A)
        {
            int temp = 0;
            for(auto& num : line)
                temp = 2 * temp + num;
            sum += temp;
        }
        return sum;
    }
};