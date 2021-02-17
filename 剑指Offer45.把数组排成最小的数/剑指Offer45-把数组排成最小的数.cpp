class Solution {
public:
    //实质上就是一个字符串的大小比较问题
    string minNumber(vector<int>& nums) {
        //将每一个数字转换成字符串之后存储在stringNum中
        vector<string> stringNum;
        for(auto& num : nums)
            stringNum.push_back(to_string(num));
        //自定义cmp，两字符串相加使length一致，如果a+b < b+a，那么应该把a排在前面
        auto cmp = [](string a, string b) {
            return a + b < b + a;
        };
        sort(stringNum.begin(), stringNum.end(), cmp);
        string result;
        //排好序的字符串直接拼接，不用去除前导0
        for(auto& str : stringNum)
            result.append(str);
        return result;
    }
};