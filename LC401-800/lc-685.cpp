#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> disjoint_set(edges.size() + 1);    //���鼯
        vector<int> fathers(edges.size() + 1);         //��¼ÿ����ĸ��ף�Ϊ���ҵ�˫��ȵ�
        vector<int> edge1(2);
        vector<int> edge2(2);
        vector<int> lastEdge_CauseCircle(2);
        for (auto pair : edges)
        {
            int u = pair[0];
            int v = pair[1];
            if (disjoint_set[u] == 0)
                disjoint_set[u] = u;
            if (disjoint_set[v] == 0)
                disjoint_set[v] = v;        //��ʼ�����鼯
// if node v already has a father, we just skip the union of this edge and check if there will be a circle �������ϲ�edge2,������ edge1,edge2
            if (fathers[v] != 0)
            {
                edge1[0] = fathers[v];
                edge1[1] = v;
                edge2[0] = pair[0];
                edge2[1] = pair[1];
            }
            else
            {
                fathers[v] = u;
                int find_set_u = find(u, disjoint_set);
                int find_set_v = find(v, disjoint_set);
                if (find_set_u != find_set_v)    //�ϲ����鼯(���鼯�������Ƚڵ����)
                    disjoint_set[find_set_v] = find_set_u;
                else
                {
                    lastEdge_CauseCircle[0] = pair[0]; //�����˻�
                    lastEdge_CauseCircle[1] = pair[1];
                }
            }
        }
        if (edge1[0] != 0 && edge2[0] != 0)
            return (lastEdge_CauseCircle[0] == 0) ? edge2 : edge1;  //�������д�˵��֮ǰ��edge1��ɾ��
        else
            return lastEdge_CauseCircle;
    }

    int find(int node, vector<int>& disjoint_set) {
        if (disjoint_set[node] == node)
            return node;
        else
        {
            disjoint_set[node] = find(disjoint_set[node], disjoint_set);
            return disjoint_set[node];
        }
    }
};