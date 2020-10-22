class Solution {
public:
    int count = 0;
    int totalNQueens(int n) {
        vector<int> P(n + 1,0);   //ȫ��������vector
        vector<bool> hashTable(n + 1,false);
        generateP(1,n,P,hashTable);
        return count;
    }

    //nλȫ�������ɣ�����1-n�еĻʺ������к�
    void generateP(int index,int n,vector<int>& P,vector<bool>& hashTable)
    {
        if(index == n+1)
        {
            count++;
            return;
        }
        for(int i = 1; i <= n; i++)    //��ǰ������index�еĻʺ�Ӧ�÷��ڵڼ���
        {
            if(hashTable[i] == false)  //��ʾ��i�л�û�з��ûʺ�ȫ���������л�û��i��
            {
                bool flag = true;      //flagΪtrue��ʾ��ǰ�ʺ���ò�����ɳ�ͻ
                for(int pre = 1; pre < index; pre++) //����֮ǰ�Ļʺ�
                {
                    //��index�еĻʺ��к�Ϊi, ��pre�еĻʺ��к�ΪP[pre]
                    if(abs(index - pre) == abs(i - P[pre]))   
                    {
                        flag= false;    //֮ǰ��index - 1�еĻʺ�����λ��һ���Խ����ϵģ���ͻ��
                        break;
                    }
                }
                if(flag)   //��ʾ���԰ѵ�index�з��ڵ�i��
                {
                    P[index] = i;
                    hashTable[i] = true;    //��ʾ��i���Ѿ����ûʺ�1-n��ȫ������������i�ˣ�
                    generateP(index+1,n,P,hashTable);
                    hashTable[i] = false;   //����
                }
            }
        }
    }
};