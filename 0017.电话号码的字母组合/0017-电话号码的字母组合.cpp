class Solution {
public:
    string temp;
    vector<string> result;
    vector<string> hash{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        dfs(0, digits);
        return result; 
    }
    void dfs(int depth, string digits) {
        if(depth == digits.size()) {
            result.push_back(temp);
            return ;
        }
        int index = digits[depth] - '2';
        //ÿһ�����ֶ�Ӧ�������ݽ�����Ӧ��ĸѡ��
        for(int i = 0; i < hash[index].size(); i++) {
            temp.push_back(hash[index][i]);
            dfs(depth+1, digits);
            temp.pop_back();
        }
    }
};