class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a)
        pq.push({a, 'a'});
        if(b)
        pq.push({b, 'b'});
        if(c)
        pq.push({c, 'c'});
        string ans = "";
        while(!pq.empty()) {
            pair<int, char> high = pq.top();
            pq.pop();
            
            if(high.first >= 2) {
                ans+=high.second;
                ans+=high.second;
                high.first-=2;
            }
            
            else {
                ans+=high.second;
                high.first-=1;
            }
            
            if(pq.empty())
                break;
            
            pair<int, char> med = pq.top();
            pq.pop();
            
            if(med.first == 1 || med.first < high.first) {
                ans+=med.second;
                med.first-=1;
            }
            
            else if(med.first >= high.first) {
                ans+=med.second;
                ans+=med.second;
                med.first-=2;
            }
            
            if(high.first)
                pq.push(high);
            if(med.first)
                pq.push(med);
        }
        return ans;
    }
};