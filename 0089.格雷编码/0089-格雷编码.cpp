class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        for(int i = 1; i <= n; i++) {
            int add = 1 << (i - 1);
            // 基于grayCode(i-1)的vector元素数量加倍，前半部分不变
            // 后半部分是前半部分翻转逆序之后二进制高位+1(十进制相当于+ 1 << (i - 1))
            for(int j = result.size()-1; j >= 0; j--) 
                result.push_back(add + result[j]);
        }
        return result;
    }
};