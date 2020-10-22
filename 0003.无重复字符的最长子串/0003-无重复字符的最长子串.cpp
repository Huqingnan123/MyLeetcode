class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int position[256]; //记录某个字符最近一次出现的位置index
        memset(position, -1, sizeof(position));
        int left=0;             //当前左边界(包含此边界)
        int maxlen=0;
        for(int i=0;i<s.length();i++)
        {
            //如果“s[i]字符还未出现过”或者“s[i]字符最近出现的位置小于left左边界”，即可长度加一
            if(position[s[i]]==-1||position[s[i]]<left) 
                maxlen=max(maxlen,i-left+1);

            //标记的position[s[i]]（上一个重复字符的下一位置）作为新的left，开始新一轮检索
            else
                left=position[s[i]]+1;
            position[s[i]]=i;
        } 
        return maxlen;
    }     
};