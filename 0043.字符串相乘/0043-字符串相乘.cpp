class Solution {
public:
    //���Ȳ����ǽ�λ���洢��λ�ϵĺͣ�ע�������ĵ�λ��num1��num2�ַ���ĩβ����
    //���걾λ��֮���ǽ�λ��projectҲ�ǵ���, �˻���λ����vectorβ��, project[0]���������λ��λ��
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> project(len1 + len2, 0);

        for(int i = num2.size() - 1; i >= 0; i--)
            for(int j = num1.size() - 1; j >= 0; j--)
                project[i+j+1] += (num1[j] - '0') * (num2[i] - '0');

        string result;
        int carry = 0;
        for(int i = project.size()-1; i >= 0; i--) {
            int sum = project[i] + carry;
            project[i] = sum % 10;
            carry = sum / 10;
            if(i != 0 || project[i] != 0)
                result.push_back(project[i] + '0');
        }
        //���result��ת����
        reverse(result.begin(), result.end());
        return result;
    }
};