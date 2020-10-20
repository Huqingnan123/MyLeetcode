#include<vector>
#include<utility>
#include<stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<int> result;
	vector<int> postorderTraversal(TreeNode* root) {
		if (root)
		{
			//bool表示是否结点第一次出现在栈顶
			stack<pair<TreeNode*, bool>> node_ptr;
			TreeNode* ptr = root;
			while (ptr != nullptr || !node_ptr.empty())
			{
				//对于一个非空结点，一直把非空左孩子入栈
				while (ptr)
				{
					node_ptr.push(make_pair(ptr, 1));
					ptr = ptr->left;
				}
				//ptr为空之后，对top元素进行考察
				if (!node_ptr.empty())
				{
					//第一次处于栈顶不弹出，去右子树进行相同操作
					if (node_ptr.top().second == 1)
					{
						node_ptr.top().second = 0;
						ptr = (node_ptr.top().first)->right;
					}
					//第二次处于栈顶弹出，说明以其为根节点的当前子树后序遍历完成
					// 并把ptr设置为nullptr，回到父亲结点处    
					else
					{
						result.emplace_back((node_ptr.top().first)->val);
						node_ptr.pop();
						ptr = nullptr;
					}
				}
			}
		}
		return result;
	}
};