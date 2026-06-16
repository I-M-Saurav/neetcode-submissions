class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 1e9));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        int i1 = p.first, j1 = p.second;
                        if (i1 > 0 && grid[i1 - 1][j1] == 1 &&
                            vis[i1 - 1][j1] > 1 + vis[i1][j1]) {
                            vis[i1 - 1][j1] = 1 + vis[i1][j1];
                            q.push({i1 - 1, j1});
                        }
                        if (j1 > 0 && grid[i1][j1 - 1] == 1 &&
                            vis[i1][j1 - 1] > 1 + vis[i1][j1]) {
                            vis[i1][j1 - 1] = 1 + vis[i1][j1];
                            q.push({i1, j1 - 1});
                        }
                        if (i1 < n - 1 && grid[i1 + 1][j1] == 1 &&
                            vis[i1 + 1][j1] > 1 + vis[i1][j1]) {
                            vis[i1 + 1][j1] = 1 + vis[i1][j1];
                            q.push({i1 + 1, j1});
                        }
                        if (j1 < m - 1 && grid[i1][j1 + 1] == 1 &&
                            vis[i1][j1 + 1] > 1 + vis[i1][j1]) {
                            vis[i1][j1 + 1] = 1 + vis[i1][j1];
                            q.push({i1, j1 + 1});
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (vis[i][j] == 1e9)
                        return -1;
                    ans = max(ans, vis[i][j]);
                }
            }
        }
        if (ans == 1e9)
            return 0;
        return ans;
    }
};