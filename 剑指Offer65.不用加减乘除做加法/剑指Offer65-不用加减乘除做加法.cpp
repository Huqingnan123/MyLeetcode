class Solution {
public:
    // si = xi ^ yi ^ ci
    // ci+1 = xi & yi + (xi ^ yi) & ci
    // use mask to get specified bits' Xi and Yi
    // from low bit 0 to high bit 31, step by step
    int add(int a, int b) {
        int sum = 0;
        int cin = 0;
        int mask = 1;
        int xi, yi, si;
        for(int i = 0; i < 32; i++) {
            xi = a & mask;
            yi = b & mask;
            si = xi ^ yi ^ cin;
            cin = xi & yi | ((xi ^ yi) & cin);
            sum ^= si;
            //shift left for next round Calculation
            if(i != 31) {
                mask <<= 1;
                cin <<= 1;
            }
        }
        return sum;
    }
};