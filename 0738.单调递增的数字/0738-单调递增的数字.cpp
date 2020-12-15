class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if(N < 10)
            return N;
        vector<int> digit;
        while(N != 0)
        {
            digit.push_back(N % 10);
            N /= 10;
        }
        reverse(digit.begin(), digit.end());
        int same_start = -1;        //���ڵ�������£������ͬ�������ֵ����
        for(int i = 0; i < digit.size() - 1; i++)
        {
            if(digit[i] < digit[i+1])
            {
                same_start = -1;    //����������
                continue;
            }
            if(digit[i] == digit[i+1])
            {
                if(same_start == -1)
                    same_start = i; //�����������Σ����
                continue;
            }    
            else                //�ҵ��ݼ����������֣���ʱ����ֱ�ӽ��������޸�
            {
                if(same_start == -1)
                {
                    digit[i]--;
                    for(int j = i+1; j < digit.size(); j++)
                        digit[j] = 9;
                    break;
                }
                else
                {
                    digit[same_start]--;
                    for(int j = same_start+1; j < digit.size(); j++)
                        digit[j] = 9;
                    break;
                }
            }
        }
        int result = 0;
        for(int i = 0; i < digit.size(); i++)
            result = result*10 + digit[i];
        return result;
    }
};