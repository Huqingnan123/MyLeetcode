class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count[1001] = {0};
        vector<int> result;
        for(auto& num : arr1)
            count[num]++;            
        for(auto& num : arr2)
        {
            for(int i = 0; i < count[num]; i++)
                result.push_back(num);
            count[num] = 0;
        }
        for(int num = 0; num <= 1000; num++)
        {
            if(count[num] != 0)
                for(int i = 0; i < count[num]; i++)
                    result.push_back(num);
        }
        return result;
    }
};