class Solution {
public:
    void helper(int i, int j, int m, int n, vector<vector<int>>& grid, vector<long long>& sum) {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0) return;

        sum[0] += 1LL*grid[i][j];
        grid[i][j] = 0;

        helper(i-1, j, m, n, grid, sum);
        helper(i+1, j, m, n, grid, sum);
        helper(i, j-1, m, n, grid, sum);
        helper(i, j+1, m, n, grid, sum);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] > 0) {
                    vector<long long> sum = {0};
                    helper(i, j, m, n, grid, sum);
                    if(sum[0]%k == 0) count++;
                }
            }
        }

        return count;
    }
};