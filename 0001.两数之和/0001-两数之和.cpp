class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first=-1;           //first用来标记target/2第一次出现的下标
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]=i;
            int another=target-nums[i];
            if(another!=nums[i] && map.find(another)!=map.end())   //不重复值相加情形
                return {map[another],i};
            if(another==nums[i]&&first==-1)
            {
                first=i;         //记录下target/2第一次出现的位置
                continue;
            }  
            if(another==nums[i]&&first!=-1)
                return {first,i};
        }
        return {};
    }
};