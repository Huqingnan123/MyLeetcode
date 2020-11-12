class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> result(A.size());
        int odd_idx = 1;
        int even_idx = 0;
        for(auto i : A)
        {
            if(i % 2)     //��������odd_idx��
            {
                result[odd_idx] = i;
                odd_idx += 2;
            }
            else          //ż������even_idx��
            {
                result[even_idx] = i;
                even_idx += 2;
            }
        }
        return result;
    }
};