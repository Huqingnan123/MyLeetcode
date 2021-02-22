class Solution {
public:
    // 1、傻瓜解法，面试时不可取！！！（没有考虑大数问题）
    // vector<int> printNumbers(int n) {
    //     vector<int> result;
    //     for(int i = 1; i < pow(10,n); i++)
    //         result.push_back(i);
    //     return result;
    // }

    //2、考虑大数问题，采用字符串表示数字（mark: n位数字的0-9递归全排列问题）
    vector<int> output;
    vector<int> printNumbers(int n) {
        string s(n, '0');
        for(int i = 0; i <= 9; i++)
        {
            s[0] = i + '0';
            //递归生成全排列
            permutation(s, s.length(), 1);
        }
        return output;
    }
    void permutation(string& s, int length, int pos)
    {
        // 此时获得n位0-9的一种排列，只要s不全'0'，就可以push进去
        // stoi函数可以自动把字符串形如: string("0002")转换成为int(2)
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