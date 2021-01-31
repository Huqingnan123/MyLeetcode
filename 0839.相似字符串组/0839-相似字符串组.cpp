class Solution {
public:
    //���鼯�ֿ鼴��
    int UnionSet[1001];
    int find_father(int v){
        if(UnionSet[v] != v)
            UnionSet[v] = find_father(UnionSet[v]);
        return UnionSet[v];
    }
    bool merge(int v1, int v2){
        int father1 = find_father(v1);
        int father2 = find_father(v2);
        if(father1 != father2)
        {
            UnionSet[father2] = father1;
            return true;
        }
        else
            return false;
    }
    int numSimilarGroups(vector<string>& strs) {
        if(strs.size() == 0)
            return 0;
        int wordLength = strs[0].size();
        //�ʼ������һ�������ַ�����
        int blockNumber = strs.size();
        //���鼯�洢�����ַ�������
        for(int i = 0; i < strs.size(); i++)
            UnionSet[i] = i;
        for(int i = 0; i < strs.size(); i++)
        {
            for(int j = i+1; j < strs.size(); j++)
            {
                int diff = 0;
                for(int k = 0; k < wordLength; k++)
                {
                    if(strs[i][k] != strs[j][k])
                        diff++;
                }
                if(diff == 2 || diff == 0)
                {
                    //�ϲ�һ��blockNumber��һ
                    if(merge(i,j) == true)
                        blockNumber--;
                }
            }
        }    
        return blockNumber; 
    }
};