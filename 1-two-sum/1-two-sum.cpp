class Solution {
    static bool comp(pair<int,int> a, pair<int, int> b) {
        return a.first<b.first;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for(int i = 0; i<n; i++)
            arr.push_back(make_pair(nums[i], i));
        sort(arr.begin(), arr.begin()+n, comp);
        int i = 0;
        int j = n-1;
        while(i<j) {
            if(arr[i].first + arr[j].first == target)
                return {arr[i].second, arr[j].second};
            else if(arr[i].first + arr[j].first < target)
                ++i;
            else
                --j;
        }
        return {};
    }
};