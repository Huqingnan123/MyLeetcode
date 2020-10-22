class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> temp_Vec;
        int vecSize = int(nums.size());
        if (vecSize <= 2)
        {
            return result;
        }
        int possibleSize = vecSize - 2; //��һ�������ѭ������������������ֻ��vecSize-2��������Ϊ��ʼ
        sort(nums.begin(), nums.end()); //�����򣨴�С����

        for (int index = 0; index < possibleSize; index++)    
        {
            int intNow = nums[index];
            if(intNow > 0){
                break;
            }
            int negativeNow = 0 - intNow;
            int low = index + 1;      //��ǰindex��ָ���ұߵĵ�һ����
            int high = vecSize - 1;   //nums���ұߵ�һ����
            while (low < high)        //ѭ������
            {
                int intLow = nums[low];
                int intHigh = nums[high];

                if (intLow + intHigh == negativeNow)
                {
                    temp_Vec = {intNow, intLow, intHigh};
                    result.push_back(temp_Vec);
                    //ȥ��
                    while (low < high && nums[low] == intLow)    //һֱ����ֱ��һ����ͬ����
                    {
                        low++;
                    }
                    while (low < high && nums[high] == intHigh)         //һֱ����ֱ��һ����ͬ����
                    {
                        high--;
                    }
                }
                else if (intLow + intHigh < negativeNow)
                {
                    low++;
                }
                else if (intLow + intHigh > negativeNow)
                {
                    high--;
                }
            }
            //ȥ��
            while (index + 1 < possibleSize && nums[index] == nums[index + 1])
            {
                index++;
            }
        }
        return result;
    }
};