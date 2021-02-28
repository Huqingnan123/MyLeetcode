class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        // ˫ָ�����м��ƶ�
        while(left <= right)
        {
            if(s[left] == s[right])
            {
                left++;
                right--;
            }
            // ɾ��left����right��ָ���ַ�����ȥ�ж��ڲ�ʣ�µ��ַ����Ƿ����(����һ��ɾ������)
            else
                return isPalindrome(s,left,right-1) || isPalindrome(s,left+1,right);
        }
        return true;
    }
    bool isPalindrome(string& s, int left, int right) {
        while(left <= right)
        {
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};