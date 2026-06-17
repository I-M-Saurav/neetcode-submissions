class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(),ans=0,j=0;
        vector<int> last(256,-1);
        for(int i=0;i<n;i++){
            j=max(j,last[s[i]]+1);
            last[s[i]]=i;
            ans=max(ans,i-j+1);
        }
        return ans;

    }
};
