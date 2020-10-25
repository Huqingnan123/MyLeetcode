class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        int maxlen = 0;
        if (n < 3)
            return 0;
        for(int i = 0, j = 1; j < A.size();)
        {
            if(A[i] >= A[j])      //双指针，A[i] >= A[j]就都往后移
            {
                i++;
                j++;
                continue;
            }
            else                  //当A[i] < A[j]时，开始先寻找递增序列（山脉左边）
            {
                while(j+1 < A.size() && A[j+1] > A[j])
                    j++;
                if(j+1 == A.size())    //说明一直递增到末尾，无法再形成山脉，直接return
                    return maxlen;
                if(A[j+1] == A[j])     //遇到两个相等的数，重新更新i,j继续寻找山脉
                {
                    i = j+1;
                    j = j+2;
                    continue;
                }
                else                   //当A[j+1] < A[j]时，再寻找递减序列（山脉右边）
                {
                    while(j+1 < A.size() && A[j+1] < A[j])
                        j++;
                    maxlen = max(maxlen,j-i+1);     //一个山脉寻找完成，作max求maxlen
                    i = j;
                    j = j+1;                        //重新更新i,j，继续寻找
                }
            }
        }
        return maxlen;
    }
};