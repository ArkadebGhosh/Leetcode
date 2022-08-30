#define lli long long int
class Solution {
public:
    static bool comp(pair<int, int> p1, pair<int, int> p2) {
        return p1.first < p2.first;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> arr;
        for(int i = 0; i<n; i++)
            arr.push_back({efficiency[i], speed[i]});
        sort(arr.begin(), arr.end(), comp);
        priority_queue<int, vector<int>, greater<int>> pq;
        lli ans = 0;
        lli sum = 0;
        int i = n-1;
        int MOD = 1e9+7;
        while(i>=0) {
            int j = i;
            while(j>=0 && arr[j].first == arr[i].first) {
                if(pq.size() < k) {
                    sum += arr[j].second;
                    pq.push(arr[j].second);
                }
                else if(pq.top() < arr[j].second) {
                    sum-=pq.top();
                    sum+=arr[j].second;
                    pq.pop();
                    pq.push(arr[j].second);
                }
                --j;
            }
            ans = max(ans, sum * arr[i].first);
            i = j;
        }
        return (int)(ans%MOD);
    }
};