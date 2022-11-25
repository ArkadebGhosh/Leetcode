class Solution {
public:
    bool safe(int x, int y, vector<vector<char>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        if(x < 0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    } 
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));
        // cout<<m<<" "<<n<<endl;
        for(int i = 0; i<m; i++) {
            if(visited[i][0] == 0 && board[i][0] == 'O')
                dfs(i, 0, board, visited);
            if(visited[i][n-1] == 0 && board[i][n-1] == 'O')
                dfs(i, n-1, board, visited);
        }
        
        for(int i = 0; i<n; i++) {
            if(visited[0][i] == 0 && board[0][i] == 'O')
                dfs(0, i, board, visited);
            if(visited[m-1][i] == 0 && board[m-1][i] == 'O')
                dfs(m-1, i, board, visited);
        }
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(visited[i][j] == 0 && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<int>>& visited) {
        visited[x][y] = 1;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        for(int i = 0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(safe(nx, ny, board) && visited[nx][ny] == 0 && board[nx][ny] == 'O') {
                dfs(nx, ny, board, visited);
            }
        }
    }
};