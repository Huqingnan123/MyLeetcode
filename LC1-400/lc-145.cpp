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
			//bool��ʾ�Ƿ����һ�γ�����ջ��
			stack<pair<TreeNode*, bool>> node_ptr;
			TreeNode* ptr = root;
			while (ptr != nullptr || !node_ptr.empty())
			{
				//����һ���ǿս�㣬һֱ�ѷǿ�������ջ
				while (ptr)
				{
					node_ptr.push(make_pair(ptr, 1));
					ptr = ptr->left;
				}
				//ptrΪ��֮�󣬶�topԪ�ؽ��п���
				if (!node_ptr.empty())
				{
					//��һ�δ���ջ����������ȥ������������ͬ����
					if (node_ptr.top().second == 1)
					{
						node_ptr.top().second = 0;
						ptr = (node_ptr.top().first)->right;
					}
					//�ڶ��δ���ջ��������˵������Ϊ���ڵ�ĵ�ǰ��������������
					// ����ptr����Ϊnullptr���ص����׽�㴦    
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