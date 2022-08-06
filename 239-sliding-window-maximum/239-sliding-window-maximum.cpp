class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        q.push_back(0);
        vector<int> ans;
        if(k==1)
            return nums;
        for(int i = 1; i < nums.size(); i++) {
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            if(!q.empty() && q.front() == i-k)
                q.pop_front();
            q.push_back(i);
            if(i>=k-1)
                ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};