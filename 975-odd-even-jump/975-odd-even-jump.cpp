class Solution {
    static bool comp1(pair<int,int> p1, pair<int,int>p2) {
        return (p1.first<p2.first) || (p1.first == p2.first && p1.second<p2.second);
    }
    
    static bool comp2(pair<int,int> p1, pair<int,int>p2) {
        return (p1.first<p2.first) || (p1.first == p2.first && p1.second>p2.second);
    }
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(2,0));
        dp[n-1][0] = dp[n-1][1] = 1;
        
        vector<pair<int, int>> arr2;
        for(int i = 0; i<n; i++)
            arr2.push_back({arr[i], i});

        sort(arr2.begin(), arr2.end(), comp1);
        vector<int> odd_dest(n,-1);
        vector<int> even_dest(n,-1);
        stack<pair<int,int>> st, st2;
        st.push(arr2[0]);
        st2.push(arr2[n-1]);
        for(int i = 1; i<n; i++) {
            while(!st.empty() && arr2[i].second > st.top().second) {
                odd_dest[st.top().second] = arr2[i].second;
                st.pop();
            }
            st.push(arr2[i]);
        }
        sort(arr2.begin(), arr2.end(), comp2);
        for(int i = 1; i<n; i++) {
            while(!st2.empty() && arr2[n-i-1].second > st2.top().second) {
                even_dest[st2.top().second] = arr2[n-i-1].second;
                st2.pop();
            }
            st2.push(arr2[n-i-1]);
        }
        int ans = 0;

        for(int i = n-2; i>=0; i--) {
            int oddjump = odd_dest[i];
            if(oddjump != -1)
                dp[i][0] = dp[oddjump][1];
            int evenjump = even_dest[i];
            if(evenjump != -1)
                dp[i][1] = dp[evenjump][0];
            if(dp[i][0] == 1)
                ++ans;
        }
        return ans+1;
        
    }
};