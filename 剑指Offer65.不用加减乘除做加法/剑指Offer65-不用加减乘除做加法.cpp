class Solution {
public:
    // ������һλȫ��������ѭ��ʵ����λ���
    // Si = Xi ^ Yi ^ Ci; Ci+1 = (Xi && Yi) || ((Xi ^ Yi) && Ci)
    int add(int a, int b) {
        if(a == 0 || b == 0)
            return (a == 0) ? b : a;
        // ��û�н�λ��ʱ���˳�ѭ��
        while(b != 0)
        {
            // C++���������������Ʋ�������Ҫ�� unsigned int
            int carry = (unsigned int)(a & b) << 1;
            // step1: ֻ���㱾λ��
            a = a ^ b;
            // step2���ټ��Ͻ�λ�ļ���
            b = carry; 
        }
        return a;
    }
};