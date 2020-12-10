class Solution {
public:
    int lengthLongestPath(string input) {
        if (input.empty()) 
            return 0;
        int n = input.size();
        vector<string> str_vec;
        int start = 0, end = 0;
        for(; end < n; end++)
        {
            if (input[end] == '\n') 
            {
                //��ͬ\tһ��洢��vec��
                str_vec.emplace_back(input.substr(start, end - start));
                start = end + 1;
            }
        }
        str_vec.emplace_back(input.substr(start, end - start));
        vector<int> pre_sum(n + 1, 0);      //pre_sum[level]�����level��Ŀ¼֮ǰ��·������
        int ans = 0;
        for (auto str : str_vec) 
        {
            int level = 0;
            while (str[level] == '\t')      //����\t�ĸ����жϲ���level
                level++;
            int len = str.size() - level;   //��ǰ�Ӵ�·������Ч����
            if (str.find('.') != string::npos)    
                ans = max(ans, pre_sum[level] + len);
            else 
                pre_sum[level + 1] = pre_sum[level] + len + 1;  //�˴���1����·���ָ���/
        }
        return ans;
    }
};