class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int position[256]; //��¼ĳ���ַ����һ�γ��ֵ�λ��index
        memset(position, -1, sizeof(position));
        int left=0;             //��ǰ��߽�(�����˱߽�)
        int maxlen=0;
        for(int i=0;i<s.length();i++)
        {
            //�����s[i]�ַ���δ���ֹ������ߡ�s[i]�ַ�������ֵ�λ��С��left��߽硱�����ɳ��ȼ�һ
            if(position[s[i]]==-1||position[s[i]]<left) 
                maxlen=max(maxlen,i-left+1);

            //��ǵ�position[s[i]]����һ���ظ��ַ�����һλ�ã���Ϊ�µ�left����ʼ��һ�ּ���
            else
                left=position[s[i]]+1;
            position[s[i]]=i;
        } 
        return maxlen;
    }     
};