class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size() < 3)
            return false;
        int i; 
        for(i = 0; i < A.size()-1; i++)
            if(A[i+1] <= A[i])
                break;
        if(i == A.size()-1 || i == 0 || A[i+1] == A[i]) //全增，全减或者遇到相等的都返回false
            return false;
        for(i = i+1; i < A.size()-1 ; i++)
        {
            if(A[i+1] >= A[i])                          //由递增进入递减，再碰到非递减就返回false
                return false;
        }
        return true; 
    }
};