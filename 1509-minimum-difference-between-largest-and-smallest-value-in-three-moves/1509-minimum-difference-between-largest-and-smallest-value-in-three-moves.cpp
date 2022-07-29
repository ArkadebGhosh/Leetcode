class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 3)
            return 0;
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> temp = nums;
        int m1 = maxmin(temp, 3, n-1);
        int m2 = maxmin(temp, 0, n-4);
        int m3 = maxmin(temp, 2, n-2);
        int m4 = maxmin(temp, 1, n-3);
        return min(m1, min(m2, min(m3, m4)));
    }
    
    int maxmin(vector<int> &arr, int start, int end) {
        int ma = arr[start], mi = arr[start];
        for(int i = start; i<=end; i++) {
            ma = max(ma, arr[i]);
            mi = min(mi, arr[i]);
        }
        return ma-mi;
    }
};