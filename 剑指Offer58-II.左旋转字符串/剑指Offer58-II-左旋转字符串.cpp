class Solution {
public:
    // ����һ��string "Abcd | Efg"������ת֮��ΪEfgAbcd,���Էֽ����ұ�E����ͷ���ֽ������d����β
    // ���ǿ��Բ��������ָ��Է�ת�������巭ת�Ľⷨ�ﵽĿ��
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(),s.begin()+n);
        reverse(s.begin()+n,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};