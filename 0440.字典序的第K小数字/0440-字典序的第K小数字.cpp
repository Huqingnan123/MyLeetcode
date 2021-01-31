//dfs十叉树（最终字典序排列就是先序遍历十叉树的顺序）
class Solution {
public:
    //求以i为前缀开头同时<=n的数字的个数
    long long getNum(long long i,long long n)
    {
        long long count=0;
        for(long long prefix=i,next=prefix+1;prefix<=n;prefix*=10,next*=10)
            count+=min(n+1,next)-prefix;
        return count;
    }
    int findKthNumber(int n, int k) 
    {
        //用index记录当前的位置
        int index=1;
        long long prefix=1;
        while(index<k)
        {
            long long count=getNum(prefix,n);
            //count算的时候是把index也就是当前位置算进去的
            //那么k要在当前子树下，即index+count-1>=k即index+count>k，更新prefix和index（prefix向下面的子树走）
            if(index+count>k)
            {
                //例如原来是1，现在变成10
                prefix*=10;
                //p从1变到了10，即字典序序号+1
                index++;
            }
            //表明k不在当前prefix的子树里（prefix向右边的兄弟节点走）
            else if(index+count<=k)
            {
                prefix++;
                index+=count;
            }
        }        
        return prefix;
    }
};