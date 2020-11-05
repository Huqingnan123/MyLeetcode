class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //便于后续构建newword的查找，提高查找速度
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) 
            return 0;
        //记录从beginword到各个string的路径长度,且防止死循环
        unordered_map<string, int> length_map; 
        queue<string> My_queue;
        My_queue.push(beginWord);
        length_map.emplace(make_pair(beginWord, 1));

        while(!My_queue.empty()) {
            string word = My_queue.front();
            My_queue.pop();
            for (int i = 0; i < word.size(); i++) 
            {
                string newWord = word;             // 每个位置依次置换一个字母构建新单词
                for (int j = 0 ; j < 26; j++) {
                    newWord[i] = j + 'a'; 
                    if (wordSet.find(newWord) != wordSet.end() 
                    && length_map.find(newWord) == length_map.end()) 
                    {    
                        if(newWord == endWord)
                            return length_map[word] + 1;
                        length_map.insert(make_pair(newWord, length_map[word] + 1));
                        My_queue.push(newWord);
                    }
                }
            }
        }
        //最后未匹配，返回长度0
        return 0;
    }
};