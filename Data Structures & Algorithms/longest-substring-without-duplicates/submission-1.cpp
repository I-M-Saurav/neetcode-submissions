class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> s1;int ct=0,j=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(!s1.count(s[i])){
                s1.insert(s[i]);ct=max(ct,(int)s1.size());
            }
            else{
                while(j<i && s1.count(s[i])){
                    s1.erase(s[j]);j++;
                }
                s1.insert(s[i]);ct=max(ct,(int)s1.size());
            }
        }
        return ct;
    }
};
