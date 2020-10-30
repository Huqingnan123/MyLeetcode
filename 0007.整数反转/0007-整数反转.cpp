class Solution {
public:
    int reverse(int x) {
        vector<int> vec;
        int status=1;
        if(x<0)
            status=0;
        x=abs(x);            //��xת��Ϊ����ȥ��ת��status�������
        while(x != 0)
        {
            vec.push_back(x%10);
            x /= 10;
        } 
        int number=0;        //number�����
        for(int i=0; i<vec.size(); i++)
        {   
            if(number>(pow(2.0,31)-1)/10 || number<(-pow(2.0,31))/10)
                return 0;
            number=number*10 + vec[i];
        }
        return (status ? number : -number);
    }
};