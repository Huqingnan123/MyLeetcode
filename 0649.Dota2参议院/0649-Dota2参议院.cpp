class Solution {
public:
    string predictPartyVictory(string senate) {
        int number_R = 0;
        int number_D = 0;
        int ToRemove_R = 0;
        int ToRemove_D = 0;  //�ĸ����������ߵ�ǰ������ �� ����Ҫ������Ȩ��������
        vector<int> is_removed(senate.size(),0);
        if(senate.size() == 1)
            return senate == "R" ? "Radiant" : "Dire";
        for(int i = 0; i < senate.size(); i++)
        {
            if(senate[i] == 'R')
                number_R++;
            else
                number_D++;
        }
        //ѭ�����У�ֱ����һ��������������0����ʤ������is_removed�������Ƿ��ѱ�ɾ��
        for(int i = 0; number_D && number_R; i = (i+1) % senate.size() )
        {
            if(senate[i] == 'R' && is_removed[i] == 0)
            {
                if(ToRemove_R != 0)
                {
                    ToRemove_R--;
                    number_R--;
                    is_removed[i] = 1;
                }
                else
                    ToRemove_D++;
            }
            else if(senate[i] == 'D' && is_removed[i] == 0)
            {
                if(ToRemove_D != 0)
                {
                    ToRemove_D--;
                    number_D--;
                    is_removed[i] = 1;
                }
                else
                    ToRemove_R++;
            }
        }
        return number_R ? "Radiant" : "Dire";
    }
};