class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 9)
            return n;
        int digitNum = 1;
        long length = 0;
        while(true)
        {
            length = countLength(digitNum);
            if(n >= length)
            {
                n -= length;
                digitNum++;
            }
            else
                break;
        }
        return countNum(digitNum, n / digitNum, n % digitNum);
    }
    //用来计算n位数有序列化后有几个字符，如num=3，则一共有900 * 3 == 2700个字符
    long countLength(int digitNum){
        if(digitNum == 1)
            return 10;
        else
            return digitNum * 9 * pow(10, digitNum-1);
    }
    //用来获取某个数字指定偏移位置的字符
    int countNum(int digitNum, int result, int bias){
        int base = 0;
        if(digitNum != 1)
            base = pow(10, digitNum-1);
        int number = base + result;
        string s_number = to_string(number);
        //转为数字字符串，很方便的获取第n位数了
        return s_number[bias] - '0';
    }
};