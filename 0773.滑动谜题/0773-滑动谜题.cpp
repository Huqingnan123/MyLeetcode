class Solution {
public:
    // ��С�ƶ���������̱仯·��֮����ⶼ��ת��Ϊ BFS ���������̱仯·��
    // �� 2x3 �Ķ�άint����ת����һά�ַ���string��״̬ת��������Ҫ�ӡ���ʼ�ַ������仯���123450����
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        string target = "123450";

        //��board�հ�ת��Ϊһά�ַ���start
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 3; j++) 
                start.push_back(board[i][j] + '0');
  
        // ��¼һά�ַ�������������
        vector<vector<int>> neighbor = {
            { 1, 3 },
            { 0, 2, 4 },
            { 1, 5 },
            { 0, 4 },
            { 1, 3, 5 },
            { 2, 4 }
        };
        
        queue<string> q;
        unordered_set<string> visited;   
        q.push(start);
        visited.insert(start);
        
        int step = 0;
        while (!q.empty()) 
        {
            //number ����һ��� string ״̬����
            int number = q.size();
            for (int i = 0; i < number; i++) 
            {
                string current = q.front(); 
                q.pop();
                // �ж��Ƿ�ﵽĿ�����
                if (target == current) 
                    return step;
                // �ҵ�����0��һάstring�е�����ֵ
                int index = 0;
                while(current[index] != '0')
                    index++;
                // ���߼���ά�հ��Ͻ�����0������λ�õ����ֽ���λ��
                for (auto adjacent : neighbor[index]) 
                {
                    string newStatus = current;
                    swap(newStatus[adjacent], newStatus[index]);
                    // ��ֹ�߻�ͷ·��δ���ֹ���״̬�ż���queue
                    if (visited.find(newStatus) == visited.end()) 
                    {
                        q.push(newStatus);
                        visited.insert(newStatus);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};