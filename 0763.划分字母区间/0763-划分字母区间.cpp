class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        //记录a-z字符各自的起始位置start和最后位置end
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
                if(char_pos[S[start] - 97].second > end)  //如果需要更新end，length也作相应变化
                {
                    length += char_pos[S[start] - 97].second - end;
                    end = char_pos[S[start] - 97].second;
                }    
            }
            result.push_back(length);                     //此时选出一个最小片段，push
            i += length;                                  //i更新到下一段字符串的起始处
        }
        return result;
    }
};