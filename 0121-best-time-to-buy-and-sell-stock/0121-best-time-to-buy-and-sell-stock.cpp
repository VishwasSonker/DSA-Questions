class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = 1, a = 0, maximum = 0;
        while(b<prices.size()){
            maximum = max(prices[b]-prices[a], maximum);
            if(prices[b]<prices[a]) a=b;
            b++;
        }
        return maximum;
    }
};