class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e8,sum=0;
        for(auto i:nums){
            sum+=i;
            ans=max(ans,sum);
            if(sum<0) sum=0;
        }
        return ans;
    }
};
