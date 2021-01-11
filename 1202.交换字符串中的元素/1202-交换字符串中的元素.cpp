class Solution {
public:
    //���鼯���������ֿ�block���ɣ�ͬ��һ��������е����������Ի����ַ���
    //�ؼ�����merge��find_father������ʵ��
    int union_Set[100000];
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //��ʼ�����鼯
        for(int i = 0; i < s.size(); i++)
            union_Set[i] = i;
        //����������������
        for(auto p : pairs)
            merge(p[0],p[1]);
        vector<vector<int>> BlockResult(s.size());
        //���˴���ͨ������������һ��vector��
        for(int i = 0; i < s.size(); i++)
            BlockResult[find_father(i)].push_back(i);
        for(int i = 0; i < s.size(); i++)
        {
            if(BlockResult[i].size() <= 1)
                continue;
            //��ͨ�������ڲ��ľֲ��ֵ�����
            string tempSort(BlockResult[i].size(),'0');
            //����ͨ�����ڲ�����С��������
            sort(BlockResult[i].begin(),BlockResult[i].end());
            for(int j = 0; j < BlockResult[i].size(); j++)
                tempSort[j] = s[BlockResult[i][j]];
            sort(tempSort.begin(),tempSort.end());
            for(int j = 0; j < BlockResult[i].size(); j++)
                s[BlockResult[i][j]] = tempSort[j];
        }
        return s;
    }
    int find_father(int v){
        if(union_Set[v] != v)
            union_Set[v] = find_father(union_Set[v]);
        return union_Set[v];
    }
    void merge(int v1, int v2){
        int father1 = find_father(v1);
        int father2 = find_father(v2);
        if(father1 != father2)
            union_Set[father2] = father1;
    }
};