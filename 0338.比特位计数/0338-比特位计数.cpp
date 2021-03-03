class Solution {
public:
    // 当i是偶数，二进制最低位一定是0，result[i] = result[i/2]，相当于bits整体左移
    // 当i是奇数，i-1的最低位是0，i相对于i-1, 最低位多一个1，故result[i] = result[i-1] + 1
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