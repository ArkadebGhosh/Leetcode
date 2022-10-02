class Solution {
public:
    struct data {
        int x, y, time;
    };
    
    bool isSafe(int x, int y, int m, int n) {
        if(x <0 || x>=m || y< 0 || y>=n)
            return false;
        return true;
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> burnt(m, vector<int> (n, -1));
        queue<data> q;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j, 0});
                    burnt[i][j] = 0;
                }
            }
        }
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        while(!q.empty()) {
            int currx = q.front().x;
            int curry = q.front().y;
            int currt = q.front().time;
            for(int i = 0; i<4; i++) {
                int nx = currx + dx[i];
                int ny = curry + dy[i];
                
                if(isSafe(nx, ny, m, n) && burnt[nx][ny] == -1 && grid[nx][ny] == 0) {
                    burnt[nx][ny] = currt+1;
                    q.push({nx, ny, currt+1});
                } 
            }
            q.pop();
        }
        
        // for(int i = 0; i<m; i++) {
        //     for(int j = 0; j<n; j++) {
        //         cout<<burnt[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int low = 0;
        int high = 20001;
        // cout<<possible(4, 0, 0, grid, burnt)<<endl;
        while(low <= high) {
            int mid = (low + high)/2;
            if(possible(mid, 0, 0, grid, burnt)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if(high == 20001)
            return 1e9;
        return high;
    }
    
    bool possible(int mins, int x, int y, vector<vector<int>> &grid, vector<vector<int>> burnt) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(burnt[i][j] != -1) {
                    burnt[i][j] = max(0, burnt[i][j] - mins);
                }
            }
        }
        
        queue<data> q;
        q.push({0, 0, 0});
        visited[x][y] = 1;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        while(!q.empty()) {
            int currx = q.front().x;
            int curry = q.front().y;
            int currt = q.front().time;
            if(currx == m-1 && curry == n-1)
                return true;
            for(int i = 0; i<4; i++) {
                int nx = currx + dx[i];
                int ny = curry + dy[i];
                
                if(isSafe(nx, ny, m, n) && grid[nx][ny] == 0 && visited[nx][ny] == 0 && 
                   (burnt[nx][ny] > currt + 1 || burnt[nx][ny] == -1 || (burnt[nx][ny] == currt+1 && nx == m-1 && ny == n-1))) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny, currt+1});
                } 
            }
            q.pop();
        }
        return false;
    }
};