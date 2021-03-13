class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index;
        //Ѱ�ҵ�һ�����������е�Ԫ��
        for(index = nums.size() - 1; index > 0; index--)
        {
            if(nums[index-1] < nums[index])
                break;
        }
        //����������һ�����������ʱ���������г���С�����У��������У�,ȫ������
        if(index == 0)
            reverse(nums.begin(), nums.end());
        //index - 1��Ӧ��Ԫ�ؼ�Ϊ��һ��������Ԫ�أ������һ����������Ԫ�ػ���λ�ã���reverse֮������
        else
        {
            int last = nums.size()-1;
            while(nums[last] <= nums[index - 1])
                last--;
            swap(nums[last],nums[index - 1]);
            reverse(nums.begin() + index, nums.end());
        }   
    }
};