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
        //��index��¼��ǰ��λ��
        int index=1;
        long long prefix=1;
        while(index<k)
        {
            long long count=getNum(prefix,n);
            //count���ʱ���ǰ�indexҲ���ǵ�ǰλ�����ȥ��
            //��ôkҪ�ڵ�ǰ�����£���index+count-1>=k��index+count>k������prefix��index��prefix������������ߣ�
            if(index+count>k)
            {
                //����ԭ����1�����ڱ��10
                prefix*=10;
                //p��1�䵽��10�����ֵ������+1
                index++;
            }
            //����k���ڵ�ǰprefix�������prefix���ұߵ��ֵܽڵ��ߣ�
            else if(index+count<=k)
            {
                prefix++;
                index+=count;
            }
        }        
        return prefix;
    }
};