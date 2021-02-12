class Solution {
public:
    //根据基本不等式可知，和一定的时候，彼此大小接近时乘积最大max
    int cuttingRope(int n) {
        int maxResult = -INT_MAX;
        int curResult = 0;
        //例如10分成3，3，4；base就是3，remain就是1
        //例如17分成3，3，3，3，3，2，base就是2，remain是5
        int remain, base;
        for(int i = 2; i <= n; i++)
        {
            remain = n % i;
            base = n / i;
            if(remain == 0)
                curResult = pow(base, i);
            else
                curResult = pow(base + 1, remain) * pow(base, i - remain);
            maxResult = max(maxResult, curResult);
        }
        return maxResult;
    }
};