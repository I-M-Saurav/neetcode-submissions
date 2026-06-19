class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        map<char,int> mp;int ct=0;
        map<int,char> mpo;
        for(auto& i:words){
            for(auto j:i) {
                if(!mp.count(j)){
                    mp[j]=ct;ct++;
                }
            }
        }
        for(auto i:mp){
            mpo[i.second]=i.first;
        }
        vector<vector<int>> a(mp.size());
        int m=mp.size();
        string s;
        set<pair<int,int>> st;
        vector<int> in(m);
        for(int i=0;i<n-1;i++){
            int j=0,siz1=words[i].length(),siz2=words[i+1].length(),siz=min(siz1,siz2);
            while(j<siz && words[i][j]==words[i+1][j])j++;
            
            if(j<siz){
                int node1=mp[words[i][j]],node2=mp[words[i+1][j]];
                if(!st.count({node1,node2})){
                    in[node2]++;
                    a[node1].push_back(node2);st.insert({node1,node2});
                }
                
            }
            else if(siz1>siz2) return "";
        }
        queue<int> q;
        for(int i=0;i<m;i++){
            if(in[i]==0)q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();q.pop();
            ans.push_back(node);
            for(int i:a[node]){
                in[i]--;
                if(!in[i])q.push(i);
            }
        }
        if(ans.size()<m) return "";
        for(auto i:ans){
            s.push_back(mpo[i]);
        }
        return s;
        
    }
};
