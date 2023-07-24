class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //vector<vector<int>> dp(n, vector<int>(n, -1));
        return cherries(grid);
    }
    
    bool isValid(int x, int y, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(x==y || x < 0 || x>=n || y<0 || y>=n)
            return false;
        return true;
    }
    
    int cherries(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> temp(n, vector<int> (n, 0));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++)
                temp[i][j] = grid[m-1][i] + grid[m-1][j];
        }
        
        for(int r = m-2; r>=0; r--) {
            // cout<<"1"<<endl;
            vector<vector<int>> temp2(n, vector<int> (n, 0));
            for(int i = 0; i<n; i++) {
                for(int j = 0; j<n; j++) {
                    // cout<<i<<" "<<j<<endl;
                    temp2[i][j] = grid[r][i] + grid[r][j];
                    int maxc = 0;
                    // cout<<"temp2: "<<temp2[i][j]<<endl;
                    for(int c1 = -1; c1<=1; c1++) {
                        for(int c2 = -1; c2 <= 1; c2++) {
                            if(isValid(i+c1, j+c2, grid)) {
                                // cout<<"EP: "<<i+c1<<" "<<j+c2<<endl;
                                maxc = max(maxc, temp[i+c1][j+c2]);
                            }                                
                        }
                    }
                    // cout<<i<<" "<<j<<" "<<maxc<<endl;
                    temp2[i][j] += maxc;
                    // cout<<maxc<<" "<<temp2[i][j]<<endl;
                }
            }
            // cout<<"3"<<endl;
            temp = temp2;
        }
        return temp[0][n-1];
    }
};