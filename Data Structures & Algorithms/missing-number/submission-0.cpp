class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int val=0,n=nums.size();
        for(int i:nums)val^=i;
        for(int i=1;i<=n;i++)val^=i;
        return val;
    }
};
