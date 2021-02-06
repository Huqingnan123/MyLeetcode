class Solution {
public:
    // 对于一个string "Abcd | Efg"，左旋转之后为EfgAbcd,所以分界线右边E是新头，分界线左边d是新尾
    // 于是可以采用两部分各自翻转，再整体翻转的解法达到目的
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.begin()+n);
        reverse(s.begin()+n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};