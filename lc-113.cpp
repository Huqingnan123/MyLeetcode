#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<int>> result;
	vector<int> temp;
	int current_sum = 0;      //不进行拷贝传参，持续更新temp和current_sum
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root)
			helper(root, sum);   //helper递归 (DFS) ，持续更新result
		return result;
	}

	void helper(TreeNode* root, int sum) {   //传入的root一定非空
		temp.emplace_back(root->val);
		current_sum += root->val;
		//到达叶子结点并且总和等于sum，存储temp
		if (!root->left && !root->right && current_sum == sum)
		{
			result.emplace_back(temp);
		}
		else {
			if (root->left)
				helper(root->left, sum);
			if (root->right)
				helper(root->right, sum);
		}
		temp.pop_back();         //函数递归返回上一层时，pop掉当前尾元素，current_sum更新回去
		current_sum -= root->val;
	}
};