class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordMap(wordList.begin(), wordList.end());
        if(wordMap.find(endWord) == wordMap.end())
            return 0;
        //��ֹ�ظ�ѡ���ʵ�����ѭ��
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
                //���԰�word��ÿһλ�ַ�����a~z���滻�������滻Ҫ�󼴿�
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