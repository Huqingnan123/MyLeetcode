class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder == "#")
            return true;
        vector<string> strVec;
        int start = 0;
        int i = 0;
        for( ; i < preorder.size(); i++) {
            if(preorder[i] != ',')
                continue;
            strVec.push_back(preorder.substr(start, i - start));
            start = i + 1;
        }
        strVec.push_back(preorder.substr(start, i - start));
        stack<string> s;
        bool first = true;
        for(auto str : strVec) {
            if(str != "#") {
                if(s.empty()) {
                    if(first == false)
                        return false;
                    first = false;
                }
                if(!s.empty())
                    s.pop();
                s.push(str);
                s.push(str);
            }
            else {
                if(!s.empty() && s.top() != "#")
                    s.pop();
                else
                    return false;
            }
        }
        return s.empty();
    }
};