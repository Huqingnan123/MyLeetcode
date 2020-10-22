class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first=-1;           //first�������target/2��һ�γ��ֵ��±�
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]=i;
            int another=target-nums[i];
            if(another!=nums[i] && map.find(another)!=map.end())   //���ظ�ֵ�������
                return {map[another],i};
            if(another==nums[i]&&first==-1)
            {
                first=i;         //��¼��target/2��һ�γ��ֵ�λ��
                continue;
            }  
            if(another==nums[i]&&first!=-1)
                return {first,i};
        }
        return {};
    }
};