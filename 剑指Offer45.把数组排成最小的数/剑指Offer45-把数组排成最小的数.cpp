class Solution {
public:
    //ʵ���Ͼ���һ���ַ����Ĵ�С�Ƚ�����
    string minNumber(vector<int>& nums) {
        //��ÿһ������ת�����ַ���֮��洢��stringNum��
        vector<string> stringNum;
        for(auto& num : nums)
            stringNum.push_back(to_string(num));
        //�Զ���cmp�����ַ������ʹlengthһ�£����a+b < b+a����ôӦ�ð�a����ǰ��
        auto cmp = [](string a, string b) {
            return a + b < b + a;
        };
        sort(stringNum.begin(), stringNum.end(), cmp);
        string result;
        //�ź�����ַ���ֱ��ƴ�ӣ�����ȥ��ǰ��0
        for(auto& str : stringNum)
            result.append(str);
        return result;
    }
};