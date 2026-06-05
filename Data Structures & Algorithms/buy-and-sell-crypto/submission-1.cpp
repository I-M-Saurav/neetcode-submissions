class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> a(prices.size()), b(prices.size());
        int curr=100;
        for(int i=0;i<prices.size();i++){
            curr=min(curr,prices[i]);a[i]=curr;
        }curr=0;
        for(int i=prices.size()-1;i>=0;i--){
            curr=max(curr,prices[i]);b[i]=curr;
        }
        int ans=0;
        for(int i=0;i<prices.size();i++){
            ans=max(ans,b[i]-a[i]);
        }
        return ans;
        
    }
};
