class Solution {
public:
    int countDigitOne(int n) {
        long digit = 1, count = 0;
        int high = n / 10, cur = n % 10, low = 0; 
        // �ֱ����1~n��n�����и���digit�ϵ�1���ֵĴ���������������ȫ��1���ֵĴ��������㹫ʽ���£�
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
            //cur����һλ������ʮλ->��λ��
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            //digit���м���ı�Ҫ
            if(!(high == 0 && cur == 0))
                digit *= 10;
            else
                break;
            
        }
        return count;
    }
};