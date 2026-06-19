class Solution {
public:
    bool dfs(int node, vector<vector<int>>& a, vector<bool>& vis, int par) {
        vis[node]=true;
        
        for(int i:a[node]){
            if(!vis[i]){
                if(!dfs(i,a,vis,node)) return false;
            }
            else if(i!=par) return false;
            
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> a(n);
        if(edges.size()!=(n-1)) return false;
        for(auto& i:edges){
            a[i[0]].push_back(i[1]);
            a[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n,false);
        bool check=true;
        // for(int i=0;i<n;i++){
            // if(!vis[i]){
                check&=(dfs(0,a,vis,-1));
            // }
        // }
        for(auto i:vis){
            if(!i) return false;
        }
        
        return check;
    }
};
