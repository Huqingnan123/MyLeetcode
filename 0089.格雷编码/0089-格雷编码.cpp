class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        for(int i = 1; i <= n; i++) {
            int add = 1 << (i - 1);
            // ����grayCode(i-1)��vectorԪ�������ӱ���ǰ�벿�ֲ���
            // ��벿����ǰ�벿�ַ�ת����֮������Ƹ�λ+1(ʮ�����൱��+ 1 << (i - 1))
            for(int j = result.size()-1; j >= 0; j--) 
                result.push_back(add + result[j]);
        }
        return result;
    }
};