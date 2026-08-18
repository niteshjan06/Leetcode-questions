class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int buy=-1;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i]<prices[i+1] && buy==-1){
                buy=i;
            }else if(prices[i]>prices[i+1] && buy!=-1){
                profit+=(prices[i]-prices[buy]);
                buy=-1;
            }
        }
        if(buy!=-1){
            profit+=(prices[prices.size()-1]-prices[buy]);
        }
        return profit;
    }
};
