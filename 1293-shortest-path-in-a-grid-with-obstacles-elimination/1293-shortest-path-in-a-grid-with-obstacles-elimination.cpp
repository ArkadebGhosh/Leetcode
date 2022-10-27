class Solution {
public:
    struct data {
        int x, y, dis, rem;
    };
    
    bool safe(int x, int y, vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(x<0 || x>=m || y<0 || y>=n)
            return false;
        return true;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        if(m==1 && n==1)
            return 0;
        int visited[m][n];
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                visited[i][j] = -1;
            }
        }
        
        queue<data> q;
        q.push({0,0,0,k});
        
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};
        
        while(!q.empty()) {
            data temp = q.front();
            q.pop();
            int currx = temp.x;
            int curry = temp.y;
            int currdis = temp.dis;
            int currk = temp.rem;
            for(int i = 0; i<4; i++) {
                int nx = currx + dx[i];
                int ny = curry + dy[i];
                // cout<<nx<<" "<<ny<<endl;
                if(nx == m-1 && ny == n-1)
                    return currdis+1;
                if(!safe(nx, ny, grid))
                    continue;
                int rem = currk;
                if(grid[nx][ny] == 1 && currk == 0)
                    continue;
                else if(grid[nx][ny] == 1)
                    rem -= 1;
                if(visited[nx][ny] >= rem) {
                    continue;
                }
                else {
                    visited[nx][ny] = rem;
                    q.push({nx, ny, currdis + 1, rem});
                }
            }
        }
        return -1;
    }
};