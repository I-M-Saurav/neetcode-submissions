class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i1=0,i2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {i1,i2};
        
    }
};
