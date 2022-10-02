class Solution {
public:
    pair<int, int> tf(int a) {
        int twos = 0, fives = 0;
        while(a%2 == 0) {
            twos+=1;
            a=a/2;
        }
        
        while(a%5 == 0) {
            fives+=1;
            a=a/5;
        }
        
        return {twos, fives};
    }
    
    int max2 (int a1, int a2, int a3, int a4, int a5, int a6) {
        return max(a1, max(a2, max(a3, max(a4, max(a5, a6)))));
    }
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        pair<int, int> tp = {0, 0};
        vector<vector<pair<int, int>>> rows(m, vector<pair<int, int>>(n, tp));
        vector<vector<pair<int, int>>> cols(n, vector<pair<int, int>>(m, tp));
        int twos = 0;
        int fives = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                pair<int, int> temp = tf(grid[i][j]);
                int t = temp.first;
                int f = temp.second;
                if(j == 0) {
                    rows[i][j] = {t, f};
                }
                else {
                    rows[i][j].first = rows[i][j-1].first + t;
                    rows[i][j].second = rows[i][j-1].second + f;
                }
                
                if(i==0) {
                    cols[j][i] = {t, f};
                }
                else {
                    cols[j][i].first = cols[j][i-1].first + t;
                    cols[j][i].second = cols[j][i-1].second + f;
                }
            }
        }
        
        // for(int i = 0; i<m; i++) {
        //     for(int j = 0; j<n; j++) {
        //         cout<<"("<<rows[i][j].first<<","<<rows[i][j].second<<")  ";
        //     }
        //     cout<<endl;
        // }
        
        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                int left2, right2, up2, down2;
                left2 = right2 = up2 = down2 = 0;
                int left5, right5, up5, down5;
                left5 = right5 = up5 = down5 = 0;
                
                if(i > 0) {
                    up2 = cols[j][i-1].first;
                    up5 = cols[j][i-1].second;
                }
                
                if(i<m-1) {
                    down2 = cols[j][m-1].first - cols[j][i].first;
                    down5 = cols[j][m-1].second - cols[j][i].second;
                }
                
                if(j > 0) {
                    left2 = rows[i][j-1].first;
                    left5 = rows[i][j-1].second;
                }
                
                if(j<n-1) {
                    right2 = rows[i][n-1].first - rows[i][j].first;
                    right5 = rows[i][n-1].second - rows[i][j].second;
                }
                
                pair<int, int> temp = tf(grid[i][j]);
                int curr2 = temp.first;
                int curr5 = temp.second;
                
                // cout<<i<<" "<<j<<" "<<left5<<" "<<right5<<" "<<up5<<" "<<down5<<endl;
                
                int currans = max2(min(left2 + right2 + curr2, left5 + right5 + curr5), 
                          min(left2 + down2 + curr2, left5 + down5 + curr5), 
                          min(left2 + up2 + curr2, left5 + up5 + curr5), 
                          min(right2 + down2 + curr2, right5 + down5 + curr5), 
                          min(right2 + up2 + curr2, right5 + up5 + curr5),
                         min(up2 + down2 + curr2, up5 + down5 + curr5));
                ans = max(ans, currans);
            }
        }
        return ans;
    }
};