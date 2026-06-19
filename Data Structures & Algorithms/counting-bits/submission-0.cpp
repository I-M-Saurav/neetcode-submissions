class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int x=i,curr_ans=0;
            while(x>0){
                curr_ans+=(x&1);x=(x>>1);
            }
            ans.push_back(curr_ans);
        }
        return ans;
    }
};
