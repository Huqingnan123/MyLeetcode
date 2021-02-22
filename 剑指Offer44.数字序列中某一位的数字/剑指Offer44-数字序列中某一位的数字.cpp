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
    //��������nλ�������л����м����ַ�����num=3����һ����900 * 3 == 2700���ַ�
    long countLength(int digitNum){
        if(digitNum == 1)
            return 10;
        else
            return digitNum * 9 * pow(10, digitNum-1);
    }
    //������ȡĳ������ָ��ƫ��λ�õ��ַ�
    int countNum(int digitNum, int result, int bias){
        int base = 0;
        if(digitNum != 1)
            base = pow(10, digitNum-1);
        int number = base + result;
        string s_number = to_string(number);
        //תΪ�����ַ������ܷ���Ļ�ȡ��nλ����
        return s_number[bias] - '0';
    }
};