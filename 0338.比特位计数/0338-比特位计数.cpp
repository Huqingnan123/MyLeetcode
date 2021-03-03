class Solution {
public:
    // ��i��ż�������������λһ����0��result[i] = result[i/2]���൱��bits��������
    // ��i��������i-1�����λ��0��i�����i-1, ���λ��һ��1����result[i] = result[i-1] + 1
    vector<int> countBits(int num) {
        if(num == 0)
            return {0};
        vector<int> result(num+1, 0);
        for(int i = 1; i <= num; i++)
        {
            if(i % 2 == 0)
                result[i] = result[i/2];
            else
                result[i] = result[i-1] + 1;
        }
        return result;
    }
};