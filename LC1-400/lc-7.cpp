#include <vector>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        vector<char> vec;
        int i, status = 1;
        int number = 0;
        if (x < 0)
            status = 0;
        x = abs(x);
        do
        {
            i = x % 10;
            x = x / 10;
            vec.push_back(i + '0');
        } while (x != 0);
        if (status == 1)
        {
            for (i = 0; i < vec.size(); i++)
            {
                if (number > (pow(2, 31) - 1) / 10 || number < (-pow(2, 31)) / 10)
                    return 0;
                number = number * 10 + (vec[i] - '0');
            }
        }
        else
        {
            for (i = 0; i < vec.size(); i++)
            {
                if (number > (pow(2, 31) - 1) / 10 || number < (-pow(2, 31)) / 10)
                    return 0;
                number = number * 10 - (vec[i] - '0');
            }
        }
        return number;
    }
};