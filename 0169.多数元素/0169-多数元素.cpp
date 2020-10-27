class Solution {
public:
    //�����кࣺܶ��ϣ��������������˴�������������ʱ��On,�ռ�O1��
    int majorityElement(vector<int>& nums) {
       int cur_num = nums[0];
       int count = 1;
       for(int i = 1; i < nums.size(); i++)
       {
            if (count == 0)        //ֱ�Ӱѵ�ǰ������Ϊ��ʼ��������
            {
                cur_num = nums[i]; 
                count = 1;
            }
            else
            {
                if (nums[i] == cur_num) 
                    count++;
                else 
                    count--;
            }
       }
       return cur_num;
    }
};