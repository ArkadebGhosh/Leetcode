class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        map<int, int> m;
        vector<int> ans;
        int n = paint.size();
        for(int i = 0;i<n; i++) {
            int left = paint[i][0];
            int right = paint[i][1];
            int total = right - left;
            
            if(m.size() == 0) {
                m[left] = right;
                ans.push_back(total);
            }
            
            else {
                // Handle greaters
                map<int, int>:: iterator it = m.lower_bound(left);
                while(it!=m.end()) {
                    int low = (*it).first;
                    int high = (*it).second;
                    it++;
                    if(low > right) {
                        break;
                    }
                    if(high <= right) {
                        total -= (high - low);
                        m.erase(low);
                    }
                    else if(high >= right) {
                        total -= (right - low);
                        right = high;
                        m.erase(low);
                    }
                }
                //Handle lessers
                it = m.lower_bound(left);
                if(m.size() == 0 || it == m.begin()) {
                    m[left] = right;
                    ans.push_back(total);
                    continue;
                }
                --it;
                int low = (*it).first;
                int high = (*it).second;
                if(high >= left) {
                    total -= (min(high, right) - left);
                    m[low] = max(right, high);
                }
                else {
                    m[left] = right;
                }
                ans.push_back(total);
            }
        }
        return ans;
    }
};