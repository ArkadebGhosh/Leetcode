class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> tails;
        vector<int> sizes;
        tails.push_back(obstacles[0]);
        sizes.push_back(1);
        for(int i = 1; i<n; i++) {
            if(obstacles[i] >= tails.back()) {
                tails.push_back(obstacles[i]);
                sizes.push_back(tails.size());
            }
            else {
                int pos = upper_bound(tails.begin(), tails.end(), obstacles[i]) - tails.begin();
                tails[pos] = obstacles[i];
                sizes.push_back(pos+1);
            }
        }
        // for(auto &it: tails)
        //     cout<<it<<" ";
        // cout<<endl;
        return sizes;
    }
};
/*
1, 2, 5, 3, 3, 6
*/