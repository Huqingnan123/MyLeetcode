# 3. 数组中重复的数字

##  3.1 题目链接

[Leetcode--剑指offer第3题](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof)

## 3.2 题目描述

在一个长度为 n 的数组里的所有数字都在 0 到 n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字是重复的，也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
```c++
Input: {2,3,1,0,2,5}

Output: 2 或 3
```

## 3.3 解题思路
+ 若要求时间复杂度 O(N)，空间复杂度 O(1)。**故不使用排序之后进行遍历，也不使用额外数组visited来标记是否重复出现**。
+ 遍历数组中的每一个num，根据其正负得到其对应的绝对值索引index，将index索引处的值取相反数变为一个非正数。
+ 以后再遇到某索引index处的数小于0，直接返回该重复的index（最后return 0用于解决只有0重复，且索引0位置为0的特殊情形)。
```c++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int index;
        for(auto num : nums)
        {
            //get the right nonegative index
            index = num > 0 ? num : -num;
            if(nums[index] < 0)
                return index;
            else
                nums[index] = -nums[index];
        }
        return 0;
    }
};
```



# 4. 二维数组中的查找

##  4.1 题目链接

[Leetcode--剑指offer第4题](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

## 4.2 题目描述

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

```c++
Consider the following input matrix:
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given input target = 5, return true.
Given input target = 20, return false.
```

## 4.3 解题思路

+ 要求时间复杂度 O(M + N)，空间复杂度 O(1)。其中 M 为行数，N 为 列数。
+ 该二维数组中的一个数，它左边的数一定小于它，它下面的数一定大于它。因此，**从右上角开始向左下角移动位置，缩小查找区间**，就可以根据 target 和当前元素的大小关系来快速地缩小查找区间。
+ 每次`row++`向下移动一行或者`col--`向左移动一列进行下一次的查找比对。当前元素的查找区间为其左下角的所有元素。
```c++
class Solution {
public:
    
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        // 从右上角开始向左下角缩小查找区间 (row++ 或者 col--)
        int row = 0;
        int col = matrix[0].size() - 1; 
        while (row <= matrix.size()-1 && col >= 0) 
        {
            if (target == matrix[row][col])
                return true;
            else if (target > matrix[row][col])
                row++;
            else if (target < matrix[row][col])
                col--;
        }
        return false;
    }
};
```