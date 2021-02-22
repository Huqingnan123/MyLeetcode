class Solution {
public:
    // 只能使用递归计算(关键在于判断特殊情形的返回条件)
    int sumNums(int n) {
        int sum = 0;
        //利用&&的阻断原则
        bool judge = (n > 0) && (sum = sumNums(n-1) + n);
        return sum;
    }
};