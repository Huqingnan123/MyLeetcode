class Solution {
public:
    //SlideWindow
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> result;
        int sum = 0;
        int left = 0, right = 0, BASE = 1;
        //SlideWindow×ó±ÕÓÒ¿ª
        while(right <= target/2 + 1)
        {
            while(sum < target)
            {
                sum += right + BASE;
                right++;
            }
            while(sum > target)
            {
                sum -= left + BASE;
                left++;
            }
            if(sum == target)
            {
                vector<int> temp;
                for(int i = left; i < right; i++)
                    temp.push_back(i + BASE);
                result.push_back(temp);
                sum += right + BASE;
                right++;
            }
        }
        return result;
    }
};