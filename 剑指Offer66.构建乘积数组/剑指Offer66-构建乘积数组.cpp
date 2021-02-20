class Solution {
public:
    //�ȴ��������۳ˣ��ٴ��������۳ˣ����Ľ�����ǡ���ȥ��������������ĳ˻�
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> B(n);
        //���������۳�
        for(int i = 0, product = 1; i < n; i++)
        {
            B[i] = product;
            product *= a[i];
        }
        //���������۳�
        for(int i = n-1, product = 1; i >= 0; i--)
        {
            B[i] *= product;
            product *= a[i];
        }
        return B;
    }
};