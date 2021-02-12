class Solution {
public:
    // 将旋转数组对半分可以得到一个包含最小元素的新旋转数组，以及另一个非递减排序的数组。
    // 由于可能有重复数字，所以遇到mid == right值的情形无法确定选哪个区间，暴力法融合right--
    int minArray(vector<int>& numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            //mid可能是最小元素，故right == mid
            if (numbers[mid] < numbers[right])
                right = mid;
            //mid不可能是最小元素，故left == mid+1
            else if (numbers[mid] > numbers[right]) 
                left = mid + 1;
            //结合暴力法缩小区间
            else if (numbers[mid] == numbers[right])
                right--;
        }
        return numbers[left];
    }
};