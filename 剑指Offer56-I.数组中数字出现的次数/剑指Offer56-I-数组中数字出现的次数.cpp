class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int mask = 0;
        //���mask��ֵ����num1 ^ num2(�ֱ�Ϊ����ֻ����һ�ε�����)��Ϊ1��λ���������������������λ
        for(int num : nums)
            mask ^= num;
        //ֻ���������ұ�һλ��1�����ֳ���һ�ε�����Ԫ�أ����������
        mask &= (-mask);      
        vector<int> result(2);
        for(int num : nums)
        {
            //������ұ�һλ1��mask�����ұ�һλ1��ͬ, ����һ��
            if(num & mask)
                result[0] ^= num;
            else
                result[1] ^= num;
        }
        return result;
    }
};