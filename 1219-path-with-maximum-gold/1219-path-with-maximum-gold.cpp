class Solution {
public:
    bool isSafe(int x, int y, vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || x>=m || y<0 || y>=n)
            return false;
        return true;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> visited(m, vector<int> (n, 0));
        int maxPossible = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                maxPossible += grid[i][j];
            }
        }
        
        
        int maxGold = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j]!=0) {
                    dfs(i, j, 0, maxGold, grid);
                    if(maxGold == maxPossible)
                        return maxPossible;
                }
            }
        }
        return maxGold;
    }
    
    void dfs(int x, int y, int sum, int &maxGold, vector<vector<int>> &grid) {
        int num = grid[x][y];
        sum+=grid[x][y];
        grid[x][y] = 0;
        maxGold = max(maxGold, sum);
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int pathAns = sum;
            if(isSafe(nx, ny, grid) && grid[nx][ny]!=0)
                dfs(nx, ny, sum, maxGold, grid);
        }
        grid[x][y] = num;
    }
};