class Solution {
public:
    int tribonacci(int n) {
        int List[3]{0,1,1};
        if(n <= 2)
            return List[n];
        else
        {
            for(int i = 3; i <= n; i++)
            {
                int next = List[0] + List[1] + List[2];
                List[0] = List[1];
                List[1] = List[2];
                List[2] = next;
            }
            return List[2];
        }
    }
};