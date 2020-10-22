class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        //��¼a-z�ַ����Ե���ʼλ��start�����λ��end
        vector<pair<int,int>> char_pos(26, make_pair(S.size()-1,0));    
        for(int i = 0; i<S.size(); i++)
        {
            char_pos[S[i] - 97].first = min(char_pos[S[i] - 97].first, i);
            char_pos[S[i] - 97].second = max(char_pos[S[i] - 97].second, i);
        }    
        for(int i = 0; i < S.size();)
        {
            int start = char_pos[S[i] - 97].first;
            int end = char_pos[S[i] - 97].second;
            int length = end - start + 1;
            while(start != end)
            {
                start++;
                if(char_pos[S[start] - 97].second > end)  //�����Ҫ����end��lengthҲ����Ӧ�仯
                {
                    length += char_pos[S[start] - 97].second - end;
                    end = char_pos[S[start] - 97].second;
                }    
            }
            result.push_back(length);                     //��ʱѡ��һ����СƬ�Σ�push
            i += length;                                  //i���µ���һ���ַ�������ʼ��
        }
        return result;
    }
};