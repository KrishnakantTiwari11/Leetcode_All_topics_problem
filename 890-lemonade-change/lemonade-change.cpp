class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change_five=0,change_ten=0,twenty_change=0;

        int n=bills.size();
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5)
            {
                change_five++;

            }
            else if(bills[i]==10)
            {
                if(change_five>0)
                {
                    change_five--;
                    change_ten++;
                }
                else
                {
                    return false;
                }
            }
            else if(bills[i]==20)
            {
                if(change_five>0 && change_ten>0)
                {
                    change_five--;
                    change_ten--;
                }
                else if(change_five>=3)
                {
                    change_five-=3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};