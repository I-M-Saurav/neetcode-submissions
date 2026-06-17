class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // if(s.length()==0) return 1;
        int curr=0,ans=0,j=0,n=s.length();
        vector<int> ch(129,0);
        for(int i=0;i<n;i++){
            int x=s[i]-32;
            if(ch[x]==0){
                ch[x]++;curr++;ans=max(ans,curr);
            }
            else{
                while(j<i && ch[x]!=0){
                    int y=s[j]-32;
                    ch[y]--;j++;
                    if(ch[y]==0)curr--;
                }
                ch[x]++;curr++;ans=max(ans,curr);
            }
        }
        cout<<ans<<"\n";
        return ans;
    }
};
