class Solution {
public:
    //先从左往右累乘，再从右往左累乘，最后的结果就是“除去本身的所有数”的乘积
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> B(n);
        //从左往右累乘
        for(int i = 0, product = 1; i < n; i++)
        {
            B[i] = product;
            product *= a[i];
        }
        //从右往左累乘
        for(int i = n-1, product = 1; i >= 0; i--)
        {
            B[i] *= product;
            product *= a[i];
        }
        return B;
    }
};