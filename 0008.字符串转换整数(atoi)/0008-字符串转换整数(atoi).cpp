class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0)
            return 0;
        int i = 0;
        while(s[i] == ' ')
            i++;
        int result = 0;
        bool positive = true;
        if(s[i] == '-')
        {
            positive = false;
            i++;
        }
        else if(s[i] == '+')
            i++;
        if(positive == true)
        {
            while(s[i] >= '0' && s[i] <= '9')
            {
                if(result >= 214748365 || (result == 214748364 && (s[i] - '0') > 7 ))
                    return 2147483647;
                result = result*10 - '0' + s[i];
                i++;
            }
            return result;
        }
        else
        {
             while(s[i] >= '0' && s[i] <= '9')
            {
                if(result <= -214748365 || (result == -214748364 && (s[i] - '0') > 8 ))
                    return -2147483648;
                result = result*10 + '0' - s[i] ;
                i++;
            }
            return result;
        }
    }
};