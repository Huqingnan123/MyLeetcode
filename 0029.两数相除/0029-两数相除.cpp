class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        if(dividend == 0)
            return 0;
        bool positive = true;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            positive = false;
        // 都转化成负数，防止溢出
        dividend = -abs(dividend);
        divisor = -abs(divisor);
        int res = div(dividend, divisor);
        return positive ? res : -res;
    }
    // a, b are negative
    int div(long a, long b){  
        if(a > b) 
            return 0;
        int count = 1;
        int tb = b; 
        while((tb - a + tb) >= 0){
            count = count + count; 
            tb = tb + tb;
        }
        // recursive
        return count + div(a - tb, b);
    }
};