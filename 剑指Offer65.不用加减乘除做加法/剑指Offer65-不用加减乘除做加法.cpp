class Solution {
public:
    // 类似于一位全加器，用循环实现逐位相加
    // Si = Xi ^ Yi ^ Ci; Ci+1 = (Xi && Yi) || ((Xi ^ Yi) && Ci)
    int add(int a, int b) {
        if(a == 0 || b == 0)
            return (a == 0) ? b : a;
        // 当没有进位的时候退出循环
        while(b != 0)
        {
            // C++不允许负数进行左移操作，故要加 unsigned int
            int carry = (unsigned int)(a & b) << 1;
            // step1: 只计算本位和
            a = a ^ b;
            // step2：再加上进位的计算
            b = carry; 
        }
        return a;
    }
};