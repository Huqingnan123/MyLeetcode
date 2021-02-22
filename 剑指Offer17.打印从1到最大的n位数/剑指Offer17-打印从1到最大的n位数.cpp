class Solution {
public:
    // 1��ɵ�Ͻⷨ������ʱ����ȡ��������û�п��Ǵ������⣩
    // vector<int> printNumbers(int n) {
    //     vector<int> result;
    //     for(int i = 1; i < pow(10,n); i++)
    //         result.push_back(i);
    //     return result;
    // }

    //2�����Ǵ������⣬�����ַ�����ʾ���֣�mark: nλ���ֵ�0-9�ݹ�ȫ�������⣩
    vector<int> output;
    vector<int> printNumbers(int n) {
        string s(n, '0');
        for(int i = 0; i <= 9; i++)
        {
            s[0] = i + '0';
            //�ݹ�����ȫ����
            permutation(s, s.length(), 1);
        }
        return output;
    }
    void permutation(string& s, int length, int pos)
    {
        // ��ʱ���nλ0-9��һ�����У�ֻҪs��ȫ'0'���Ϳ���push��ȥ
        // stoi���������Զ����ַ�������: string("0002")ת����Ϊint(2)
        if(pos == length)
        {
            if(s != string(s.size(),'0')) 
                output.push_back(stoi(s));
            return; 
        }
        for(int i = 0; i <= 9; i++)
        {
            s[pos] = i + '0';
            permutation(s, length, pos + 1);
        }
    }
};