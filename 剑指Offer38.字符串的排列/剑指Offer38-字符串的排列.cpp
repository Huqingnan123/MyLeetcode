class Solution {
public:
    //1������ֱ�Ӳ���sort֮��next_permutationһֱ������һ������

    //2��������stl�еĺ��������Բ���dfs�����㷨������˼·ͬȫ���Т񣬢��⣨46��47�⣩
    vector<string> permutation(string s) {
        vector<string> res;
        dfs(s, res, 0);
        return res;
    }

    void dfs(string& s, vector<string>& res, int depth)
    {
        if(depth == s.size()-1)
        {
            res.push_back(s);
            return ;
        }
        unordered_set<char> used;  //�ֲ�setȥ��
        for(int i = depth; i < s.size(); ++i)
        {
            if(used.find(s[i]) != used.end())   continue;   //ȥ��
            used.insert(s[i]);
            swap(s[depth],s[i]);
            dfs(s, res, depth+1);
            swap(s[depth],s[i]);        //���ݳ�������
        }
    }
};