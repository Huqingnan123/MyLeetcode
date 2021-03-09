class Solution {
public:
    vector<string> res;
    void DFS(string temp,int num_1,int num_2, int n) {
        if (num_1 < num_2 || num_1 > n) return ;
        if (temp.length() == n * 2) {
            res.emplace_back(temp);
        }
        temp += '(';
        DFS(temp, num_1 + 1, num_2, n);
        temp.pop_back();
        temp += ')';
        DFS(temp, num_1, num_2 + 1, n);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        DFS("",0,0,n);
        return res;
    }
};