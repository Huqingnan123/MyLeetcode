class Solution {
public:
    int count = 0;
    int totalNQueens(int n) {
        vector<int> P(n + 1,0);   //全排列生成vector
        vector<bool> hashTable(n + 1,false);
        generateP(1,n,P,hashTable);
        return count;
    }

    //n位全排列生成，代表1-n列的皇后所在行号
    void generateP(int index,int n,vector<int>& P,vector<bool>& hashTable)
    {
        if(index == n+1)
        {
            count++;
            return;
        }
        for(int i = 1; i <= n; i++)    //当前决定第index列的皇后应该放在第几行
        {
            if(hashTable[i] == false)  //表示第i行还没有放置皇后（全排列序列中还没有i）
            {
                bool flag = true;      //flag为true表示当前皇后放置不会造成冲突
                for(int pre = 1; pre < index; pre++) //遍历之前的皇后
                {
                    //第index列的皇后行号为i, 第pre列的皇后行号为P[pre]
                    if(abs(index - pre) == abs(i - P[pre]))   
                    {
                        flag= false;    //之前的index - 1列的皇后已有位于一条对角线上的，冲突！
                        break;
                    }
                }
                if(flag)   //表示可以把第index列放在第i行
                {
                    P[index] = i;
                    hashTable[i] = true;    //表示第i行已经放置皇后（1-n的全排列序列中有i了）
                    generateP(index+1,n,P,hashTable);
                    hashTable[i] = false;   //回溯
                }
            }
        }
    }
};