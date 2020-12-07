class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        //̰��
        //����ÿһ�У���λ��0��������ת��
        int line_sum = 0;
        for(auto& line : A)
        {
            line_sum++;
            if(line[0] == 0)     
                for(auto& num : line)
                    num ^= 1;
        }
        //����ÿһ�У�1�ĸ�����0���������ת��
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
        //�����
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