class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        //��Ҫ��ʱ�临�Ӷ� O(N)���ռ临�Ӷ� O(1)���ʲ�ʹ��sort����ķ�����Ҳ��ʹ�ö���ı������visited
        //����������num�����������õ���Ӧ�ľ���ֵ�Ǹ�����index����index��������ֵ����ȡ�෴������λ��һ����Ϊ������
        //�Ժ�������ĳ����index������С��0��ֱ�ӷ���index�����return 0���ڽ��ֻ��0�ظ�������0λ�øպ�Ϊ0����������)
        int index;
        for(auto num : nums)
        {
            //get the right nonegative index
            index = num > 0 ? num : -num;
            if(nums[index] < 0)
                return index;
            else
                nums[index] = -nums[index];
        }
        return 0;
    }
};