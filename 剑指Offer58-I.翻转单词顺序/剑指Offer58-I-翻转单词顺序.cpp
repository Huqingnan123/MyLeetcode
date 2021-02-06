class Solution {
public:
    //1、分割单词再逆序拼接（使用了额外空间）
    // string reverseWords(string s) {
    //     vector<string> words;
    //     string result;
    //     //Split出每一个单词
    //     for(int i = 0; i < s.size(); i++)
    //     {
    //         if(s[i] == ' ')
    //             continue;
    //         else
    //         {
    //             int start = i;
    //             while(i < s.size() && s[i] != ' ')
    //                 i++;
    //             words.push_back(s.substr(start,i-start));
    //         }
    //     }
    //     if(words.size() == 0)
    //         return "";
    //     //将单词vector倒序之后拼接即可
    //     reverse(words.begin(), words.end());
    //     for(int i = 0; i < words.size() - 1; i++)
    //         result += words[i] + " ";
    //     result += words[words.size()-1];
    //     return result;
    // }

    //2、采用先去除所有冗余空格，再翻转每个单词，再翻转整个字符串的O(1)空间的解法
    string reverseWords(string s) {
        s = removeExtraspace(s);
        int n = s.size();
        int left = 0, right = 0;
        while(right <= n)
        {
            if(right == n || s[right] == ' ')
            {
                reverse(s.begin()+left, s.begin()+right);
                left = right+1;
            }
            right++;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string removeExtraspace(string s) {
        int left = 0, right = s.size()-1;
        //先用双指针去除首尾多余空格
        while(left <= right)
        {
            if(s[left] != ' ' && s[right] != ' ')
                break;
            if(s[left] == ' ')
                left++;
            if(s[right] == ' ')
                right--;
        }
        if(left <= right)
            s = s.substr(left, right - left + 1);
        else
            return "";
        //再去除单词之间的多余空格
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] == ' ' && s[i+1] == ' ')
            {
                //由于擦除一个空格，所以更新索引i--
                s.erase(s.begin()+i);
                i--;
            }    
        }
        return s;
    }
};