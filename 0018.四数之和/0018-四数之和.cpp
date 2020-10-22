class Solution {
public:
   vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i <= length - 4; i++)
        {
            //nums[i]�������������Ҳ����target��������һ��nums[i++],continue
            if (nums[i] + nums[length-3] + nums[length-2] + nums[length-1] < target)   
                continue;
            for (int j = i + 1; j <= length - 3; j++)
            {
                //nums[i]����nums[j]֮������������target�󣬴�ʱ�����ٽ���Ѱ�ң�ֱ�ӽ�����һ��j, break��������i
                if (nums[j] + nums[i] + nums[j+1] + nums[j+2] > target)     
                    break;
                int remain_sum = target - nums[j] - nums[i];
                int low = j + 1;
                int high = length - 1;
                while (low < high)
                {
                    int intLow = nums[low];
                    int intHigh = nums[high];
                    if (intLow + intHigh == remain_sum)     //�ҵ���������Ϊremain_sum
                    {
                        result.emplace_back(vector<int> {nums[i], nums[j], intLow, intHigh});
                        //��Ҫȥ�أ��Ƶ�����������ͬ������
                        while (low < high && nums[low] == intLow)
                            low++;
                        while (low < high && nums[high] == intHigh)
                            high--;
                    }
                    else if (intLow + intHigh > remain_sum)
                        high--;
                    else
                        low++;
                }
                //������ͬ��nums[j]ֵ
                while (j+1 <= length - 3 && nums[j] == nums[j+1])
                    j++;
            }
            //������ͬ��nums[i]ֵ
            while (i+1 <= length - 4 && nums[i] == nums[i+1])
                i++;
        }
        return result;
    }
};