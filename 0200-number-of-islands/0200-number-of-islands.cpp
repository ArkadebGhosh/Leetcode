class Solution {
public:
    bool safe(int x, int y, vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    ++ans;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return ans;
    }
    
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        visited[x][y] = 1;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        for(int i = 0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(safe(nx, ny, grid) && visited[nx][ny] == 0 && grid[nx][ny] == '1') {
                dfs(nx, ny, grid, visited);
            }
        }
    }
};