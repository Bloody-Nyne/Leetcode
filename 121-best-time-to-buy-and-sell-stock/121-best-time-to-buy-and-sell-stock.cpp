class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        int minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++){
            int price=prices[i];
            minPrice=min(minPrice,price);
            maxPro=max(maxPro,price-minPrice);
        }
        return maxPro;
    }
};