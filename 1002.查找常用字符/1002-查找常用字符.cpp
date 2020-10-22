class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int char_number[100][26] {0};
        int number = 100;
        vector<string> result;
        for(int i = 0; i <= A.size()-1; i++)
        {
            for(int j = 0; j <= A[i].size()-1 ; j++)
            {
                char_number[i][A[i][j] - 97]++;       //A[i][j] - 97为ASCII的哈希下标
            }    
        }
        for(int i = 0; i <= 25 ; i++)                 //从a~z扫描找出各自最少的次数
        {
            number = 100;
            for(int j = 0; j <= A.size()-1 ; j++)
                number = min(number, char_number[j][i]);
            while(number-- != 0)
                result.emplace_back(string(1, i+97));
        }
        return result;
    }
};