class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(),m = typed.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if (name[i] != typed[j]) 
                return false;
            else if (i == n - 1) 
            {  //i移到最后仍相等，只需单移j（后面要全部相等）
                for(int k = j; k < m; k++) 
                    if(typed[k] != name[i]) 
                        return false;
                return true;   
            }
            else if (j < m-1 && typed[j] == typed[j+1] && i < n-1 && name[i] != name[i+1]) 
            { //连续两个j相等，且连续两个i不等，只需单移j
                while(j+1 < m && typed[j] == typed[j+1])  //把相同的j移完
                    j++;
                i++;
                j++;
            } 
            else 
            {  //其他情况，i和j平移
                i++;
                j++;
            }
        }
        return false;
    }
};