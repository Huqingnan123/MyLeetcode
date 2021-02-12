class Solution {
public:
    //���ݻ�������ʽ��֪����һ����ʱ�򣬱˴˴�С�ӽ�ʱ�˻����max
    int cuttingRope(int n) {
        int maxResult = -INT_MAX;
        int curResult = 0;
        //����10�ֳ�3��3��4��base����3��remain����1
        //����17�ֳ�3��3��3��3��3��2��base����2��remain��5
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