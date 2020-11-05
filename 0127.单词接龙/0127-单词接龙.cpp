class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //���ں�������newword�Ĳ��ң���߲����ٶ�
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) 
            return 0;
        //��¼��beginword������string��·������,�ҷ�ֹ��ѭ��
        unordered_map<string, int> length_map; 
        queue<string> My_queue;
        My_queue.push(beginWord);
        length_map.emplace(make_pair(beginWord, 1));

        while(!My_queue.empty()) {
            string word = My_queue.front();
            My_queue.pop();
            for (int i = 0; i < word.size(); i++) 
            {
                string newWord = word;             // ÿ��λ�������û�һ����ĸ�����µ���
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
        //���δƥ�䣬���س���0
        return 0;
    }
};