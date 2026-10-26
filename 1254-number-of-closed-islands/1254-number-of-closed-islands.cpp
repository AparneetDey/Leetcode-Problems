class Solution {
public:
    bool dfs(int i, int j, int row, int col, vector<vector<int>>& grid) {
        if (i<0 || j<0 || i>=row || j>=col) return false;

        if(grid[i][j] == 1) return true;

        grid[i][j] = 1;
        bool left = dfs(i-1, j, row, col, grid);
        bool right = dfs(i+1, j, row, col, grid);
        bool up = dfs(i, j-1, row, col, grid);
        bool down = dfs(i, j+1, row, col, grid);

        return left && right && up && down;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int count = 0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] == 0 && dfs(i, j, row, col, grid)) count++;
            }
        }

        return count;
    }
};