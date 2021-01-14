# 3. 数组中重复的数字

##  题目链接

[Leetcode--剑指offer第3题](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof)

## 题目描述

在一个长度为 n 的数组里的所有数字都在 0 到 n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字是重复的，也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
```c++
Input: {2,3,1,0,2,5}

Output: 2 或 3
```

## 解题思路
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

##  题目链接

[Leetcode--剑指offer第4题](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)

## 题目描述

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

## 解题思路

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



# 61. 扑克牌中的顺子

##  题目链接

[Leetcode--剑指offer第61题](https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/)

## 题目描述

从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

```c++
Input: {0,0,1,2,5}

Output: True
```

## 解题思路

+ 首先对所给的长度为5的数组排序，这样按照升序排列，有万能牌0的话就会在最开始出现
+ 然后先统计数组开头0的个数，便于后续判断是否能连成顺子。
+ 遇到连续相同的不为0的数必定不是顺子，遇到间隔大于1的情形，需要判断0的数量是否足够。

```c++
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int zeroNum = 0;
        int i = 0;
        while(nums[i++] == 0)
            zeroNum++;
        for( ; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                return false;
            else if(nums[i] - nums[i-1] > 1)
            {
                if(zeroNum >= nums[i] - nums[i-1] - 1)
                    zeroNum = zeroNum - nums[i] - nums[i-1] + 1;
                else
                    return false;
            }
        }
        return true;
    }
};
```



# 63. 股票的最大利润

##  题目链接

[Leetcode--剑指offer第63题](https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/)

## 题目描述

假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

```c++
Input: {7,1,5,3,6,4}

Output: 5

Hint: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 
```

## 解题思路
+ 此题相对简单，一次买卖的目标就在于求解从第二天开始，每一天的价格与前面`minPrice`的价格之差最大值。
+ 为了体现动态规划，还是使用了一维dp数组，采用minPrice变量存储之前出现的最小价格。dp[i]表示第i天能获得的最大利润。
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        int dp[prices.size()];     //only one chance for buy and sale
        int minPrice = prices[0];  
        dp[0] = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            dp[i] = max(dp[i-1], prices[i] - minPrice);
            minPrice = min(prices[i], minPrice);
        }
        return dp[prices.size()-1];
    }
};
```



# 68 - Ⅰ. 二叉搜索树的最近公共祖先

##  题目链接

[Leetcode--剑指offer第68 -Ⅰ题](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/)

## 题目描述

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
>最近公共祖先的定义：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/binarysearchtree_improved.png)

```c++
Input: p = 2, q = 8

Output: 6（节点 2 和节点 8 的最近公共祖先是 6）

Input: p = 2, q = 4

Output: 2（节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身）

Hint: 题目告诉我们所有节点的值都是唯一的，p、q 为不同节点且均存在于给定的二叉搜索树中。
```

## 解题思路
+ 这一题的二叉树是一个二叉搜索树，满足`root->val >= root->left->val && root->val <= root->right->val`这一性质。
+ 当前root的值比p,q二者的值都要大的时候，进入左子树继续递归寻找。
+ 当前root的值比p,q二者的值都要小的时候，进入右子树继续递归寻找。
+ 除去上述两种情形，要么root的值介于p,q二者之间（p,q分居左右子树），要么root就是p,q二者之中的一个，则root就是最终答案。
```c++
class Solution {
public:
    //二叉搜索树： root->val >= p->val && root->val <= q->val 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
            return nullptr;
        //go to left branch
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        //go to right branch
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        //this root is the lowestCommonAncestor  
        return root;
    }
};
```



# 68 - Ⅱ. 普通二叉树的最近公共祖先

##  题目链接

[Leetcode--剑指offer第68 - Ⅱ题](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/)

## 题目描述

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

>最近公共祖先的定义：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/binarytree.png)

```c++
Input: p = 5, q = 1

Output: 3（节点 5 和节点 1 的最近公共祖先是 3）

Input: p = 5, q = 4

Output: 5（节点 5 和节点 4 的最近公共祖先是 5, 因为根据定义最近公共祖先节点可以为节点本身）

Hint: 题目告诉我们所有节点的值都是唯一的，p、q 为不同节点且均存在于给定的二叉树中。
```

## 解题思路

+ 这一题的二叉树只是一个普通二叉树，不具备二叉搜索树中节点大小关系性质。**对左右子树一直递归查找即可。**
+ 在左右子树中分别查找是否存在 p 或者 q，如果 p 和 q 分别在两个子树中，那么left和right非空，说明根节点就是最近公共祖先。
+ 如果 p 和 q 同处于左子树或者右子树中，那么left和right中一个为空，一个不为空，就直接返回不为空的那一个就是最近公共祖先。
```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != nullptr && right != nullptr)
            return root;
        else
            return left ? left : right;
    }
};
```