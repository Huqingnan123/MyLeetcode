class Solution {
public:
    //���ݻ�������ʽ��֪����һ����ʱ�򣬱˴˴�С�ӽ�ʱ�˻����max
    int cuttingRope(int n) {
        if(n == 2)  
            return 1;    
        if(n == 3)
            return 2; 
        long long result = 1;
        //����֤�������������Ӽ��ɳ���Ϊ3��С�Σ�����4�������ٷֳ�һС��3���������Ϊ4�ֳ�2*2
        while(n > 4)
        {
            n -= 3;
            result = result * 3 % 1000000007;
        }
        // 4���Ҳ��ֳ�2*2���˻�Ϊ4
        return result * n % 1000000007;
    }
};