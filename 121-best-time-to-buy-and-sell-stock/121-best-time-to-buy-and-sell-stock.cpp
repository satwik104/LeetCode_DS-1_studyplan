//solution which came to mind first...but it will not pass the test case with lowest price //at last like 7 2 3 5 1, max profit should be 3 not 0
/*
int maxProfit(vector<int>& prices) {
        int min=prices[0],buy_day=0,i;
        for( i=1;i<prices.size();i++)
        {
            if(prices[i]<min)
            {
                min=prices[i];
                buy_day=i;
            }
        }
        
        if(buy_day==prices.size()-1)
            return 0;
        int max=prices[buy_day+1];
        for(int j=buy_day+1;j<prices.size();j++)
        {
            if(prices[j]>max)
                max=prices[j];
        }
        int profit = max-min;
        return profit;
    }
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lsf = INT_MAX;//least price till now
        int op = 0;//overall profit
        int pist = 0;//profit if sold today
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < lsf){
                lsf = prices[i];
            }
            pist = prices[i] - lsf;
            if(op < pist){
                op = pist;
            }
        }
        return op;
    }
};
