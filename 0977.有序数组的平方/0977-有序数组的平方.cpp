class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> result;
        int index;
        for(index = 0; index <= A.size()-1 ; index++)
            if(A[index] >= 0)            //find the first non-negtive number index
                break;
        int index_left = index - 1;
        int index_right = index;         //double pointer from middle to left and right
        while(index_right <= A.size()-1 && index_left >= 0)
        {
            if(A[index_left]*A[index_left] <= A[index_right]*A[index_right])
            {
                result.push_back(A[index_left]*A[index_left]);
                index_left--;
            }
            else
            {
                result.push_back(A[index_right]*A[index_right]);
                index_right++;
            }
        }
        //when any side get to the end
        if(index_right > A.size()-1)
            while(index_left >= 0)
            {
                result.push_back(A[index_left]*A[index_left]);
                index_left--;
            }    
        else if(index_left < 0)
            while(index_right <= A.size()-1)
            {
                result.push_back(A[index_right]*A[index_right]);
                index_right++;
            }    
        return result;
    }
};