class Solution {
public:
    //˫ָ�뼴�ɣ�upΪ��ġ�����������İڶ����г��ȣ�downΪ��ġ�����½����İڶ����г���
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int up = 1;
        int down = 1;
        for (int i = 1; i < nums.size(); i++) 
        {
            //ֻҪnums[i] > nums[i-1]���ڶ����п������down���еĻ�����+1����
            if (nums[i] > nums[i-1]) 
                up = down + 1;
            //ֻҪnums[i] < nums[i-1]���ڶ����п������up���еĻ�����+1����
            else if (nums[i] < nums[i-1]) 
                down = up + 1;
        }
        return max(up, down);
    }
};