class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto i:nums) s.insert(i);
        int ans =0, curr = -1e9-1, ct=0;
        for(auto i:s){
            if(i == curr +1){
                ct++;
            }
            else{
                ct=1;
            }
            curr = i;
            ans=max(ans,ct);
        }
        return ans;

        
    }
};
