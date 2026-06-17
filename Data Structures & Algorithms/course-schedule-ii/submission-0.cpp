class Solution {
public:
    bool dfs(int node, vector<vector<int>>& a, vector<bool>& vis,
             vector<bool>& path, vector<int>& ans) {
        vis[node] = true;
        path[node] = true;
        bool check = false;
        for (auto i : a[node]) {
            if (!vis[i]) {
                check |= dfs(i, a, vis, path, ans);
            } else if (path[i])
                return true;
        }
        path[node] = false;
        ans.push_back(node);
        return check;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> a(numCourses);
        for (auto i : prerequisites) {
            a[i[0]].push_back(i[1]);
        }
        vector<bool> vis(numCourses, false), path(numCourses, false);
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, a, vis, path, ans))
                    return {};
            }
        }
        return ans;
    }
};