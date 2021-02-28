class Solution {
public:
    //本题的关键是右指针的初始化，实现剪枝，从而降低时间复杂度
    bool judgeSquareSum(int c) {
        int left = 0, right = sqrt(c);
        while(left <= right)
        {
            long long result = pow(right,2) + pow(left,2);
            if(result == c)
                return true;
            else if(result > c)
                right--;
            else
                left++;
        }
        return false;
    }
};