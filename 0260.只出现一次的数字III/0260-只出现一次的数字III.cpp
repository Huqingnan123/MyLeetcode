class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int dis_mask = 0;
        for(auto& num : nums)  //k���Ϊ1��λ�ô���a,b��������0��1�����λ��
            dis_mask ^= num;
        dis_mask &= (-dis_mask);      //ֻ���������ұ�һλ��1�����ֳ���һ�ε�����Ԫ�أ����������
        vector<int> result(2,0);
        for(auto& num : nums)
        {
            if(num & dis_mask)        //����dis_mask��a,b�ŵ�������ֱ����ó�
                result[0] ^= num;
            else
                result[1] ^= num;
        }
        return result; 
    }
};