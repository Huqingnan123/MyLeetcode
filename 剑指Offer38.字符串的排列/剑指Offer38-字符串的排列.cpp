class Solution {
public:
    //1������ֱ�Ӳ���sort֮��next_permutationһֱ������һ������

    //2��������stl�еĺ��������Բ���dfs�����㷨������˼·ͬȫ���Т񣬢��⣨46��47�⣩
    vector<string> permutation(string s) {
        vector<string> result;
        dfs(s, result, 0);
        return result;
    }
    void dfs(string& s, vector<string>& result, int depth) {
        if(depth == s.size())
        {
            result.push_back(s);
            return ;
        }
        //��¼��ǰdepth֮���Ѿ�����λ�õ��ַ�����ֹ�ظ��滻��ͬ�ַ���depthλ��
        unordered_set<char> used;
        //��ǰ���depth,������֮���ַ�һһ����λ�ã���ֹȥ�أ�
        for(int i = depth; i < s.size(); i++)
        {
            if(used.find(s[i]) != used.end())
                continue;
            used.insert(s[i]);
            swap(s[depth], s[i]);
            dfs(s, result, depth+1);
            //���ݳ�������
            swap(s[depth], s[i]);
        }
    }
};