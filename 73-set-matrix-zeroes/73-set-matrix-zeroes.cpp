class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // O(n) space
        // int m = matrix.size();
        // int n = matrix[0].size();
        // // vector<vector<int>> temp(n, vector<int> (m, 0));
        // vector<vector<int>> temp = matrix;
        // for(int i=0; i<m; i++) {
        //     for(int j = 0; j<n; j++) {
        //         if(temp[i][j] == 0) {
        //             for(int a=0; a<m; a++)
        //                 matrix[a][j] = 0;
        //             for(int b = 0; b<n; b++)
        //                 matrix[i][b] = 0;
        //         }
        //     }
        // }
        
        // O(1) space
        int m = matrix.size();
        int n = matrix[0].size();
        bool col = false;
        for(int j = 0; j<n; j++) {
            if(matrix[0][j] == 0) {
                col = true;
                break;
            }
        }
        
        
        for(int i = 1; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<m; i++) {
            if(matrix[i][0]== 0)
               for(int j = 1; j<n; j++)
                   matrix[i][j] = 0;
        }
        
        for(int j = 0; j<n; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i<m; i++)
                matrix[i][j] = 0;
            }
        }
        
        if(col) {
            for(int j = 0; j<n; j++)
                matrix[0][j] = 0;
        }
            
    }
};