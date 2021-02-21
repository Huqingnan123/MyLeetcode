class Solution {
public:
    // 一个长度为n的约瑟夫环，删除的第一个元素应该是 m % n - 1，下一个位置元素是m % n
    // 删除第一个元素之后，剩下的数字环就可以对应一个长度为n-1的约瑟夫环
    // 长度为n-1的约瑟夫环是从0，1，2，..., n-2的环，元素对应关系：0 -> m % n; 1 -> (m+1) % n
    // 对于n-1长度的约瑟夫环结果x,（x + m）% n就是长度为n的约瑟夫环结果，所以一直向下递归即可
    int lastRemaining(int n, int m) {
        if(n == 1)
            return 0;
        // 根据n-1的约瑟夫环的结果x, 由(x+m) % n计算得到n的约瑟夫环结果
        return (lastRemaining(n-1, m) + m) % n;
    }
};