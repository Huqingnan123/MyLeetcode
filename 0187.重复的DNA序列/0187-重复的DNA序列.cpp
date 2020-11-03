class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10)
            return {};
        vector<string> result;
        unordered_set<string> all_string;     //�洢���еĳ���Ϊ10���Ӵ�
        unordered_set<string> myresult;       //�洢�Ѿ�����ĳ����������ε��Ӵ�����ֹ�ظ����һ���Ķ�γ��ֵ��Ӵ�
        for(int i = 0; i <= s.size() - 10; i++)
        {
            string temp_string = s.substr(i,10);
            //��γ�����֮ǰû����������Ӵ������
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