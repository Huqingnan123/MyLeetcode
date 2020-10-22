class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(),m = typed.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if (name[i] != typed[j]) 
                return false;
            else if (i == n - 1) 
            {  //i�Ƶ��������ȣ�ֻ�赥��j������Ҫȫ����ȣ�
                for(int k = j; k < m; k++) 
                    if(typed[k] != name[i]) 
                        return false;
                return true;   
            }
            else if (j < m-1 && typed[j] == typed[j+1] && i < n-1 && name[i] != name[i+1]) 
            { //��������j��ȣ�����������i���ȣ�ֻ�赥��j
                while(j+1 < m && typed[j] == typed[j+1])  //����ͬ��j����
                    j++;
                i++;
                j++;
            } 
            else 
            {  //���������i��jƽ��
                i++;
                j++;
            }
        }
        return false;
    }
};