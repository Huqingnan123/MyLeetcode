class Solution {
public:
    string predictPartyVictory(string senate) {
        int number_R = 0;
        int number_D = 0;
        int ToRemove_R = 0;
        int ToRemove_D = 0;  //四个变量，两边当前的人数 和 还需要被剥夺权利的人数
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
        //循环进行，直到有一方人数被削减到0决出胜负，用is_removed数组标记是否已被删除
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