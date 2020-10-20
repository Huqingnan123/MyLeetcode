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
	int current_sum = 0;      //�����п������Σ���������temp��current_sum
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root)
			helper(root, sum);   //helper�ݹ� (DFS) ����������result
		return result;
	}

	void helper(TreeNode* root, int sum) {   //�����rootһ���ǿ�
		temp.emplace_back(root->val);
		current_sum += root->val;
		//����Ҷ�ӽ�㲢���ܺ͵���sum���洢temp
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
		temp.pop_back();         //�����ݹ鷵����һ��ʱ��pop����ǰβԪ�أ�current_sum���»�ȥ
		current_sum -= root->val;
	}
};