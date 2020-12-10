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
                //连同\t一起存储在vec中
                str_vec.emplace_back(input.substr(start, end - start));
                start = end + 1;
            }
        }
        str_vec.emplace_back(input.substr(start, end - start));
        vector<int> pre_sum(n + 1, 0);      //pre_sum[level]代表第level级目录之前的路径长度
        int ans = 0;
        for (auto str : str_vec) 
        {
            int level = 0;
            while (str[level] == '\t')      //根据\t的个数判断层数level
                level++;
            int len = str.size() - level;   //当前子串路径的有效长度
            if (str.find('.') != string::npos)    
                ans = max(ans, pre_sum[level] + len);
            else 
                pre_sum[level + 1] = pre_sum[level] + len + 1;  //此处的1代表路径分隔符/
        }
        return ans;
    }
};