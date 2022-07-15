// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
    public:
    static bool comp(pair<int, int> a, pair<int,int> b) {
        if(a.second < b.second)
        return true;
        return false;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meetings;
        for(int i = 0; i<n; i++)
            meetings.push_back({start[i], end[i]});
        sort(meetings.begin(), meetings.end(), comp);
        int ans = 1;
        vector<pair<int,int>> possible;
        possible.push_back(meetings[0]);
        for(int i = 1; i<n; i++) {
            if(meetings[i].first > possible.back().second) {
                possible.push_back(meetings[i]);
                ++ans;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends