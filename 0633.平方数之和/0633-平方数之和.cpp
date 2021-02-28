class Solution {
public:
    //����Ĺؼ�����ָ��ĳ�ʼ����ʵ�ּ�֦���Ӷ�����ʱ�临�Ӷ�
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