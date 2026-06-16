class Solution {
   public:
    void dfs(int node, vector<vector<int>>& a, vector<bool>& vis) {
        vis[node] = true;
        for (auto i : a[node]) {
            if (!vis[i]) {
                dfs(i, a, vis);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> a(n);
        for (auto i : edges) {
            a[i[0]].push_back(i[1]);
            a[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, a, vis);
            }
        }
        return count;
    }
};
