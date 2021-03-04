/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // 层序遍历即可
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";
        string result;
        queue<TreeNode*> q;
        q.push(root);
        //左右孩子是nullptr也会被push进入队列
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            if(cur == nullptr)
                result.append("null");
            else
            {
                result.append(to_string(cur->val));
                q.push(cur->left);
                q.push(cur->right);
            }
            //字符串内部逗号分隔
            result.append(",");
            q.pop();
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return nullptr;
        //首先处理序列化的字符串，根据逗号位置取出子串来新建树结点
        vector<TreeNode*> vec;
        for(int i = 0; i < data.size(); i++)
        {
            for(int j = i+1; j < data.size(); j++)
            {
                if(data[j] == ',')
                {
                    string s = data.substr(i,j-i);
                    if(s != "null")
                    {
                        TreeNode* cur = new TreeNode(stoi(s));
                        vec.push_back(cur);
                    }
                    else
                        vec.push_back(nullptr);
                    i = j;
                    break;
                }
            }
        }
        //层序TreeNode*序列还原二叉树
        int nextIndex = 1;
        for(int i=0; i < vec.size(); i++)
        {
            if(vec[i] == nullptr) 
                continue;
            //vec[i]非空就按序列顺序nextIndex分配left和right孩子
            if(nextIndex < vec.size()) 
                vec[i]->left = vec[nextIndex++];
            if(nextIndex < vec.size()) 
                vec[i]->right = vec[nextIndex++];
        }
        return vec[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));