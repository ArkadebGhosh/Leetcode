class Solution {
public:
    int m, n;
    bool isValid(int x, int y) {
        if(x < 0 || x>=m || y<0 || y>=n)
            return false;
        return true;
    }
    
    void checkNeighbors(int x, int y, vector<vector<int>>& board) {
        vector<int> dx = {0, 0, 1, 1, -1, -1, -1, 1};
        vector<int> dy = {1, -1, 0, 1, 1, -1, 0, -1};
        int c = 0;
        for(int i = 0; i<8; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isValid(nx, ny) && (board[nx][ny] == 1 || board[nx][ny] == -1))
                ++c;
        }
        if(board[x][y] == 1 && (c<2 || c>3))
            board[x][y] = -1;
        else if(board[x][y] == 0 && c==3)
            board[x][y] = 2;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                checkNeighbors(i, j, board);
            }
        }
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(board[i][j] == -1)
                    board[i][j] = 0;
                if(board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
        
    }
};