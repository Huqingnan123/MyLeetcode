class Solution {
public:
    string reverseVowels(string s) {
        //hashSet±ãÓÚ²éÕÒ
        unordered_set<char> Myset{'a','e','i','o','u','A','E','I','O','U'};
        int left = 0, right = s.size()-1;
        while(left < right)
        {
            if(Myset.find(s[left]) == Myset.end() && Myset.find(s[right]) == Myset.end())
            {
                left++;
                right--;
            }
            else if(Myset.find(s[left]) == Myset.end() && Myset.find(s[right]) != Myset.end())
                left++;
            else if(Myset.find(s[left]) != Myset.end() && Myset.find(s[right]) == Myset.end())
                right--;
            else    
                swap(s[left++], s[right--]);
        }
        return s;
    }
};