#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int count = 0;
    int totalNQueens(int n) {
        vector<int> P(n + 1,0);   //全排列生成vector
        vector<bool> hashTable(n + 1,false);
        generateP(1, n, P, hashTable);
        return count;
    }

    //n位全排列生成，代表1-n行的皇后各自所在列号
    void generateP(int index, int n, vector<int>& P, vector<bool>& hashTable)
    {
        if (index == n + 1)
        {
            count++;
            cout << "第" << count << "种n皇后问题格局如下：" << endl;
            for (int line = 1; line <= n; line++)   //打印结果
            {
                for (int col = 1; col <= n; col++)
                {
                    if (P[line] == col)        
                        cout << "$";
                    else
                        cout << "_";
                    cout << " ";
                }
                cout << endl;
            }
            cout << "相应的全排列为： ";
            for (int pos = 1; pos<=P.size()-1; pos++)
                cout << P[pos] << " ";
            cout << endl << endl << endl;
            return;
        }
        for (int i = 1; i <= n; i++)    //当前决定第index行的皇后应该放在第几列
        {
            if (hashTable[i] == false)  //表示第i列还没有放置皇后（全排列序列中还没有i）
            {
                bool flag = true;      //flag为true表示当前皇后放置不会造成冲突
                for (int pre = 1; pre < index; pre++) //遍历之前的皇后
                {
                    //第index行的皇后列号为i, 第pre行的皇后列号为P[pre]
                    if (abs(index - pre) == abs(i - P[pre]))
                    {
                        flag = false;    //与之前的index - 1行的某个皇后位于一条对角线上，冲突！
                        break;
                    }
                }
                if (flag)   //表示可以把第index行皇后放在第i列
                {
                    P[index] = i;
                    hashTable[i] = true;    //表示第i列已经放置皇后（1-n的全排列序列中有i了）
                    generateP(index + 1, n, P, hashTable);
                    hashTable[i] = false;   //回溯
                }
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;        //the order
    Solution s;
    cout << s.totalNQueens(n);
    return 0;
}
