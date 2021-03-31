class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordMap(wordList.begin(), wordList.end());
        if(wordMap.find(endWord) == wordMap.end())
            return 0;
        //防止重复选单词导致死循环
        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(beginWord); 
        visited[beginWord] = true;
        int level = 1;
        while(!q.empty()) {
            int number = q.size();
            while(number-- != 0) {
                string word = q.front();
                q.pop();
                if(word == endWord)
                    return level;
                //尝试把word的每一位字符进行a~z的替换，符合替换要求即可
                for(int i = 0; i < word.size(); ++i) {
                    string temp = word;
                    for(int j = 0; j < 26; ++j) {
                        temp[i] = j + 'a';
                        if(wordMap.find(temp) != wordMap.end() && visited.find(temp) == visited.end()) {
                            q.push(temp);
                            visited[temp] = true;
                        }    
                    }
                }
            }
            level++;
        }
        return 0;
    }
};