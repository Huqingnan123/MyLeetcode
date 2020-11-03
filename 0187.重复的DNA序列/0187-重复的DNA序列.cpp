class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10)
            return {};
        vector<string> result;
        unordered_set<string> all_string;     //存储所有的长度为10的子串
        unordered_set<string> myresult;       //存储已经输出的出现至少两次的子串，防止重复输出一样的多次出现的子串
        for(int i = 0; i <= s.size() - 10; i++)
        {
            string temp_string = s.substr(i,10);
            //多次出现且之前没有输出过的子串才输出
            if(all_string.find(temp_string) != all_string.end() && myresult.find(temp_string) == myresult.end())
            {
                result.push_back(temp_string);
                myresult.emplace(temp_string);
            }  
            all_string.emplace(temp_string);  
        }
        return result;
    }
};