class Solution {
public:
    int countDigitOne(int n) {
        long digit = 1, count = 0;
        int high = n / 10, cur = n % 10, low = 0; 
        // 分别计算1~n这n个数中各个digit上的1出现的次数，加起来就是全部1出现的次数，计算公式如下：
        // cur = 0 : high * digit
        // cur = 1 : high * digit + low + 1
        // cur = 2 ~ 9 : high * digit + digit = (high + 1) * digit
        while(true)
        {
            if(cur == 0)
                count += high * digit;
            else if(cur == 1)
                count += high * digit + low + 1;
            else
                count += (high + 1) * digit;
            //cur左移一位（例如十位->百位）
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            //digit还有计算的必要
            if(!(high == 0 && cur == 0))
                digit *= 10;
            else
                break;
            
        }
        return count;
    }
};