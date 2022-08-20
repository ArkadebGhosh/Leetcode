class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int low = 1;
        int high = n-1;
        while(low <= high) {
            int dis = (low + high)/2;
            vector<int> prefix(n, 0);
            vector<int> suffix(n, 0);
            prefix[0] = seats[0];
            
            for(int i = 1; i<n; i++)
                prefix[i] = prefix[i-1] + seats[i];
            
            bool valid = false;
            
            for(int i = 0; i<n; i++) {
                if(seats[i] == 1)
                    continue;
                int prev = i - dis;
                int next = i + dis;
                int prevsum = 0;
                if(prev>=0)
                    prevsum = prefix[prev];
                if(prefix[i] - prevsum > 0)
                    continue;
                else if(prefix[min(n-1, next-1)] - prefix[i] > 0)
                    continue;
                else {
                    valid = true;
                    break;
                }
            }
            if(valid == false) 
                high = dis - 1;
            else 
                low = dis+1;
        }
        return high;
    }
};