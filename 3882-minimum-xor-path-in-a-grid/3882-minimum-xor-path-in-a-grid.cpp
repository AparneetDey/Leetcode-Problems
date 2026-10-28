class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    int dfs(int i, int j, int temp, vector<vector<int>>& grid) {
        if(i >= n || j >= m) {
            return INT_MAX;
        }

        temp ^= grid[i][j];
        if(i == n-1 && j == m-1) return temp;
        if(dp[i][j][temp] != -1) return dp[i][j][temp];

        int right = dfs(i+1, j, temp, grid);
        int left = dfs(i, j+1, temp, grid);

        return dp[i][j][temp] = min(right, left);
    }
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(1024, -1)));

        return dfs(0, 0, 0, grid);
    }
};