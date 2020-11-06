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

    //����__builtin_popcount()�滻�Զ���Cal_oneNum, ���ڼ���һ�� 32 λ�޷��������ж��ٸ�λΪ1
    vector<int> sortByBits(vector<int>& arr) {
        auto My_cmp = [&](int a,int b)->bool {
            int num1 = __builtin_popcount(a);
            int num2 = __builtin_popcount(b);
            return num1 < num2 || (num1 == num2 && a <= b);   //lambda�Զ���Ƚ�
        };
        sort(arr.begin(), arr.end(), My_cmp);
        return arr;
    }
};