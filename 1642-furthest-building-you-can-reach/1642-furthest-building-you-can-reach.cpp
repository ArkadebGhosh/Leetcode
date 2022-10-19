class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        int limit = n-1;
        for(int i = 1; i<n; i++) {
            int climb = heights[i] - heights[i-1];
            if(climb > 0 && ladders > 0) {
                ladders -= 1;
                pq.push(climb);
            }
            else if(climb > 0) {
                if(pq.empty()) {
                    if(bricks >= climb)
                        bricks-=climb;
                    else {
                        limit = i-1;
                        break;
                    }
                }
                else {
                    int minclimb = pq.top();
                    int currclimb = heights[i] - heights[i-1];
                    if(currclimb <= minclimb && bricks >= currclimb) {
                        bricks -= currclimb;
                    }
                    else if(currclimb > minclimb && bricks >= minclimb) {
                        bricks -= minclimb;
                        pq.pop();
                        pq.push(currclimb);
                    }
                    else {
                        limit = i-1;
                        break;
                    }
                }
            }
        }
        return limit;
    }
};