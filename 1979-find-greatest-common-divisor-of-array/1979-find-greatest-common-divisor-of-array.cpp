class Solution {
public:
    int findGCD(vector<int>& nums) {
        int high = INT_MIN;
        int low = INT_MAX;
        for(int i = 0; i<nums.size(); i++) {
            high = max(high, nums[i]);
            low = min(low, nums[i]);
        }
        return gcd(high, low);
    }
    
    int gcd(int a, int b) {
        return (b==0) ? a: gcd(b, a%b);
    }
};