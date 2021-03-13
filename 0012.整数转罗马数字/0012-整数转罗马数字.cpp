class Solution {
public:
    //贪心，从大到小符号遍历
    string intToRoman(int num) {
        string Romans[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4 ,1};
        string ans;
        for(int i = 0; i < 13; i++) {
            while(num >= values[i]) {
                ans += Romans[i];
                num -= values[i];
            }
        }
        return ans;
    }
};