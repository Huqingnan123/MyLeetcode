#include <Unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> map;
        int nums;
        for (auto s : S)
            map[s]++;
        for (auto j : J)
            if (map.find(j) != map.end())
                nums += map[j];
        return nums;
    }
};