class Solution {
public:
    bool isSafe(int x, int y, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        
        int maxArea = 0;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    int areaComp = 0;
                    dfs(i, j, grid, visited, areaComp);
                    maxArea = max(maxArea, areaComp);
                }
            }
        }
        return maxArea;
    }
    
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited, int &areaComp) {
        if(visited[x][y]) {
            return;
        }
        visited[x][y] = 1;
        areaComp+=1;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isSafe(nx, ny, grid) && !visited[nx][ny] && grid[nx][ny] == 1) {
                dfs(nx, ny, grid, visited, areaComp);
            }
        }
    }
};