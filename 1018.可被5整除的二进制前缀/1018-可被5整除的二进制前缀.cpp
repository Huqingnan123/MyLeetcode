class Solution {
public:
    //ֱ�Ӽ����������ֵsumҲ����������Կ���ÿ�ζ�ģ5ȥ��5��������
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> result;
        int sum = 0;
        for(auto digit : A)
        {
            sum = sum * 2 + digit;
            if(sum % 5 == 0)
                result.push_back(true);
            else
                result.push_back(false);
            sum %= 5;
        }
        return result;
    }
};