class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        unordered_set<int> s;
        for(auto &it: nums)
            sum+=it;
        if(sum%2==1)
            return false;
        int req = sum/2;
        for(auto &it: nums) {
            vector<int> temp;
            if(it == req)
                return true;
            for(auto &ele: s) {
                int newsum = ele + it;
                if(newsum == req)
                    return true;
                if(s.find(newsum) == s.end())
                temp.push_back(newsum);
            }            
            s.insert(temp.begin(), temp.end());
            s.insert(it);
        }
        return false;
    }
};

/*
1 5 11 5
*/