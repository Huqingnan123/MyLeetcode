class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill_5 = 0;
        int bill_10 = 0;
        for(auto bill : bills)
        {
            if(bill == 5)         //ֱ����ȡ5Ԫ
                bill_5++;
            else if(bill == 10)
            {
                if(bill_5 != 0)   //��10Ԫ��5Ԫ
                {
                    bill_5--;
                    bill_10++;
                }
                else
                    return false;
            }
            else if(bill == 20)
            {
                if(bill_10 != 0 && bill_5 != 0)      //��10Ԫ������10Ԫ+5Ԫ
                {
                    bill_5--;
                    bill_10--;
                }
                else if(bill_10 == 0 && bill_5 >= 3) //û��10Ԫ��3��5Ԫ
                {
                    bill_5-=3;
                }
                else
                    return false;
            }   
        }
        return true;
    }
};