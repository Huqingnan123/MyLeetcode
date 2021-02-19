class Solution {
public:
    //根据基本不等式可知，和一定的时候，彼此大小接近时乘积最大max
    int cuttingRope(int n) {
        if(n == 2)  
            return 1;    
        if(n == 3)
            return 2; 
        long long result = 1;
        //经过证明：尽量把绳子剪成长度为3的小段，大于4都可以再分出一小段3，对于最后为4分成2*2
        while(n > 4)
        {
            n -= 3;
            result = result * 3 % 1000000007;
        }
        // 4最后也会分成2*2，乘积为4
        return result * n % 1000000007;
    }
};