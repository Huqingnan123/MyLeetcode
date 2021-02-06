class Solution {
public:
    //1���ָ��������ƴ�ӣ�ʹ���˶���ռ䣩
    // string reverseWords(string s) {
    //     vector<string> words;
    //     string result;
    //     //Split��ÿһ������
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
    //     //������vector����֮��ƴ�Ӽ���
    //     reverse(words.begin(), words.end());
    //     for(int i = 0; i < words.size() - 1; i++)
    //         result += words[i] + " ";
    //     result += words[words.size()-1];
    //     return result;
    // }

    //2��������ȥ����������ո��ٷ�תÿ�����ʣ��ٷ�ת�����ַ�����O(1)�ռ�Ľⷨ
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
        //����˫ָ��ȥ����β����ո�
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
        //��ȥ������֮��Ķ���ո�
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] == ' ' && s[i+1] == ' ')
            {
                //���ڲ���һ���ո����Ը�������i--
                s.erase(s.begin()+i);
                i--;
            }    
        }
        return s;
    }
};