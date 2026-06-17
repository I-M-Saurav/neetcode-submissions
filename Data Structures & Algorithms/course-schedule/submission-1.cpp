class Solution {
public:
    bool dfs(int node, vector<vector<int>>& a, vector<bool>& vis, vector<bool>& path) {
        vis[node]=true;path[node]=true;
        bool check=false;
        for(auto i:a[node]){
            if(!vis[i]){
                check|=dfs(i,a,vis,path);
            }
            else if(path[i]) return true;
        }
        path[node]=false;
        return check;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> a(numCourses);
        for(auto i:prerequisites){
            a[i[0]].push_back(i[1]);
        }
        vector<bool> vis(numCourses,false), path(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,a,vis,path)) return false;
            }
        }
        return true;
    }
};
