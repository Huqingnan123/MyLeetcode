//dfsʮ�����������ֵ������о����������ʮ������˳��
class Solution {
public:
    //����iΪǰ׺��ͷͬʱ<=n�����ֵĸ���
    long long getNum(long long i,long long n)
    {
        long long count=0;
        for(long long prefix=i,next=prefix+1;prefix<=n;prefix*=10,next*=10)
            count+=min(n+1,next)-prefix;
        return count;
    }
    int findKthNumber(int n, int k) 
    {
        //��p��¼��ǰ��λ��
        int p=1;
        long long prefix=1;
        while(p<k)
        {
            long long count=getNum(prefix,n);
            //count���ʱ���ǰ�pҲ���ǵ�ǰλ�����ȥ��
            //��ôkҪ�ڵ�ǰ�����£���p+count-1>=k��p+count>k
            if(p+count>k)
            {
                //����ԭ����1�����ڱ��10
                prefix*=10;
                //p��1�䵽��10�����ֵ������+1
                p++;
            }
            //����k���ڵ�ǰprefix��������
            else if(p+count<=k)
            {
                prefix++;
                p+=count;
            }
        }        
        return prefix;
    }
};