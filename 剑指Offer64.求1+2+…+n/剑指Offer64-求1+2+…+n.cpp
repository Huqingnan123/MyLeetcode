class Solution {
public:
    // ֻ��ʹ�õݹ����(�ؼ������ж��������εķ�������)
    int sumNums(int n) {
        int sum = 0;
        //����&&�����ԭ��
        bool judge = (n > 0) && (sum = sumNums(n-1) + n);
        return sum;
    }
};