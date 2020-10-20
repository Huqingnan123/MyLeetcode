#include <string>
class Solution {
public:
    int romanToInt(std::string s) {
        int num = 0;
        char Roman[7]{ 'M','D','C','L','X','V','I' };
        int Number[7]{ 1000,500,100,50,10,5,1 };
        if (s.size() == 1)
        {
            int k = 0;
            while (s[0] != Roman[k])
                k++;
            num += Number[k];
        }
        else
        {
            for (int i = 0, k1 = 0, k2 = 0; i <= s.size() - 1; i++, k1 = 0, k2 = 0)
            {
                if (i != s.size() - 1)
                {
                    while (s[i] != Roman[k1])
                        k1++;
                    while (s[i + 1] != Roman[k2])
                        k2++;
                    if (Number[k2] > Number[k1])
                    {
                        num += (Number[k2] - Number[k1]);
                        i++;
                    }
                    else
                        num += Number[k1];
                }
                else
                {
                    while (s[i] != Roman[k1])
                        k1++;
                    num += Number[k1];
                }
            }
        }
        return num;
    }
};