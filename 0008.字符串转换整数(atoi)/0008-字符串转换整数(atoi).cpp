class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0)
            return 0;
        int i = 0;
        int result = 0;
        while(s[i] == ' ')
            i++;
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
                if(result > INT_MAX/10 || (result == INT_MAX/10 && (s[i] - '0') > 7 ))
                    return INT_MAX;
                result = result * 10 - '0' + s[i];
                i++;
            }
            return result;
        }
        else
        {
             while(s[i] >= '0' && s[i] <= '9')
            {
                if(result < INT_MIN/10 || (result == INT_MIN/10 && (s[i] - '0') > 8 ))
                    return INT_MIN;
                result = result*10 + '0' - s[i] ;
                i++;
            }
            return result;
        }
    }
};