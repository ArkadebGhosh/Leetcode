class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n= matrix[0].size();
        vector<int> ans;
        int start = 0;
        while(ans.size() < m*n) {
            for(int i = start; i<n-start && ans.size() < m*n; i++)
                ans.push_back(matrix[start][i]);
            for(int i = start+1; i<m-start && ans.size() < m*n; i++)
                ans.push_back(matrix[i][n-start-1]);
            for(int i = n-start-2; i>=start && ans.size() < m*n; i--)
                ans.push_back(matrix[m-start-1][i]);
            for(int i = m-start-2; i>=start+1 && ans.size() < m*n; i--) {
                ans.push_back(matrix[i][start]);
            }
            ++start;
        }
        return ans;
    }
};