class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(strs.empty())                         //strs�գ�ֱ�ӷ���
            return result;
        for(int i = 0; i<strs[0].size(); i++)    //�Ե�һ���ַ������ַ���Ϊ�Ƚϱ�׼��һֱ����
        {  
            for(int j = 1; j<strs.size(); j++)   
            {
                if(strs[j][i] == strs[0][i])
                    continue;
                else
                    return result;
            }
            result.push_back(strs[0][i]);       //���ҽ��������ַ�����λ���ϵ��ַ���һ�£�push_back
        }
        return result;
    }
};