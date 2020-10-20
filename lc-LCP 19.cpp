#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//动态规划， 使用 3 个 dp 数组记录状态（0-i字符序列的状态有3种，纯红，红->黄， 红->黄->红）
//dp[0][i] 代表从头开始到当前第i个字符全部为红，需要修改几次
//dp[1][i] 代表从头开始到当前第i个字符要求过程是 红->黄，需要修改几次
//dp[2][i] 代表从头开始到当前第i个字符要求过程是 红->黄->红，需要修改几次
//根据当前的 i 是红是黄，判断转移情况
//dp[0][i] 就很简单，如果第i个字符是黄的，就比之前加一
//dp[1][i] 可以从”之前纯红+自己黄”变化过来，也可以从“红->黄 + 自己黄”变化过来
//dp[2][i] 可以从“之前红->黄+自己红”变化过来，也可以从“红->黄->红 + 自己红”变化过来

class Solution {
public:
    int minimumOperations(string leaves) {
        vector<vector<int>> dp(3, vector<int>(leaves.size(), 0));
        //从状态0依次更新到状态2，所以最后要求的答案即：dp[2].back()
        for (int i = 0; i < leaves.size(); i++) {
            if (i < 1) {
                dp[0][i] = (leaves[i] != 'r');   //第一个不是r需要替换
            }
            else {
                dp[0][i] = dp[0][i - 1] + (leaves[i] != 'r');
            }

            if (i < 1) {
                dp[1][i] = dp[0][i];      //承继0状态下的所用替换次数（初始化）
            }
            else {
                //当前状态可以由两种状态转换而来，leaves[i]最后为'y'，不为y就要进行一次替换
                dp[1][i] = min(dp[0][i - 1] + (leaves[i] != 'y'), dp[1][i - 1] + (leaves[i] != 'y'));
            }

            if (i < 2) {
                dp[2][i] = dp[1][i];     //承继1状态下的所用替换次数（初始化）
            }
            else {
                //当前状态可以由两种状态转换而来，leaves[i]最后为'r'，不为r就要进行一次替换
                dp[2][i] = min(dp[1][i - 1] + (leaves[i] != 'r'), dp[2][i - 1] + (leaves[i] != 'r'));
            }
        }
        return dp[2].back();
    }
};