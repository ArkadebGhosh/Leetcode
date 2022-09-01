class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int, int>> arr;
        
        for(int i = 0; i<profits.size(); i++)
            arr.push_back({capital[i], profits[i]});
        
        sort(arr.begin(), arr.end());
        int funds = w;
        int i = 0;
        int n = profits.size();
        if(arr[0].first > w)
            return w;
        
        while(i<n && k>0) {
            if(arr[i].first <= funds) {
                pq.push(arr[i].second);
                ++i;
            }
            else {
                while(!pq.empty() && k>0 && funds < arr[i].first) {
                    funds+=pq.top();
                    pq.pop();
                    --k;
                }
                if(funds < arr[i].first)
                    break;
            }
        }
        
        while(k>0 && !pq.empty()) {
            funds+=pq.top();
            pq.pop();
            --k;
        }
        return funds;
    }
};