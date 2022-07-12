class Solution {
    
    bool valid(int x, int y, vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        if(x >= m || y>=n || x<0 || y<0)
            return false;
        return true;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> visited (m, vector<int> (n, 0));
        
        for(int i = 0; i<m; i++) {
            if(visited[i][0] != 1)
                dfs(i, 0, 1, heights, visited);
        }
        
        for(int i = 0; i<n; i++) {
            if(visited[0][i] != 1)
                dfs(0, i, 1, heights, visited);
        }
        
        // for(int i = 0; i<m; i++) {
        //     for(int j = 0; j<n; j++)
        //         cout<<visited[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<"\n\n";
        for(int i = 0; i<m; i++) {
            if(visited[i][n-1] != 2 && visited[i][n-1] != 3)
                dfs(i, n-1, 2, heights, visited);
        }
        
        for(int i = 0; i<n; i++) {
            if(visited[m-1][i] != 2 &&  visited[m-1][i] != 3)
                dfs(m-1, i, 2, heights, visited);
        }
        
        // for(int i = 0; i<m; i++) {
        //     for(int j = 0; j<n; j++)
        //         cout<<visited[i][j]<<" ";
        //     cout<<endl;
        // }
        
        vector<vector<int>> ans;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(visited[i][j] == 3)
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
    
    void dfs(int x, int y, int ocean, vector<vector<int>> &heights, vector<vector<int>> &visited) {
        if(visited[x][y] != 1)
        visited[x][y] = ocean;
        else
        visited[x][y] = 3;
        
        // if(ocean == 1) {
        //     visited[x][y] = 1;
        // }
        // else {
        //     if(visited[x][y] == 1 || visited[x][y] == 3)
        //         visited[x][y] = 3;
        //     else
        //         visited[x][y] = 2;
        // }
        
        vector<int> dx = {0, 1, -1, 0};
        vector<int> dy = {1, 0, 0, -1};
        // cout<<"Current: "<<x<<" "<<y<<" "<<visited[x][y]<<endl;
        for(int i = 0; i<4; i++) {
            
            if(valid(x+dx[i], y+dy[i], heights) && heights[x+dx[i]][y+dy[i]] >= heights[x][y]) {
                // cout<<"Neightbours: "<<x+dx[i]<<" "<<y+dy[i]<<endl;
                if((ocean == 1 && visited[x+dx[i]][y+dy[i]] == 0) || (ocean == 2 && visited[x+dx[i]][y+dy[i]] <2))
                    dfs(x+dx[i], y+dy[i], ocean, heights, visited);
            } 
        }
        
    }
};