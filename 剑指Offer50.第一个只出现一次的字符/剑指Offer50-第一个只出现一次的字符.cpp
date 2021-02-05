class Solution {
public:
    char firstUniqChar(string s) {
        int visited[256] {0};
        for(char ch : s)
            visited[ch]++;
        for(char ch : s)
            if(visited[ch] == 1)
                return ch;
        return ' ';
    }
};