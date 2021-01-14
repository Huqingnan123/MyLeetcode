class Solution {
public:
    //直接计算二进制真值sum也会溢出，所以可以每次都模5去除5的整数倍
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