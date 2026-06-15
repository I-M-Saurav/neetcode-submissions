class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& a, vector<vector<bool>>& vis,
             int n, int m) {
        vis[i][j] = true;
        for (int deli = -1; deli <= 1; deli++) {
            for (int delj = -1; delj <= 1; delj++) {
                if ((deli == 0 || delj == 0)) {
                    int ni = i + deli, nj = j + delj;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                        a[ni][nj] == '1' && !vis[ni][nj]) {
                        dfs(ni, nj, a, vis, n, m);
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, grid, vis, n, m);
                }
            }
        }
        return count;
    }
};