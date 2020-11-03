class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3)
            return false;
        int i; 
        for(i = 0; i < A.size()-1; i++)
            if(A[i+1] <= A[i])
                break;
        if(i == A.size()-1 || i == 0 || A[i+1] == A[i]) //ȫ����ȫ������������ȵĶ�����false
            return false;
        for(i = i+1; i < A.size()-1 ; i++)
        {
            if(A[i+1] >= A[i])                          //�ɵ�������ݼ����������ǵݼ��ͷ���false
                return false;
        }
        return true; 
    }
};