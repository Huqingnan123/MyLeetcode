class Solution {
public:
    // int Cal_oneNum(int num){
    //     int number = 0;
    //     while(num){
    //         number += (num % 2);
    //         num /= 2;
    //     }
    //     return number;
    // }

    //采用__builtin_popcount()替换自定义Cal_oneNum, 用于计算一个 32 位无符号整数有多少个位为1
    vector<int> sortByBits(vector<int>& arr) {
        auto My_cmp = [&](int a,int b)->bool {
            int num1 = __builtin_popcount(a);
            int num2 = __builtin_popcount(b);
            return num1 < num2 || (num1 == num2 && a <= b);   //lambda自定义比较
        };
        sort(arr.begin(), arr.end(), My_cmp);
        return arr;
    }
};