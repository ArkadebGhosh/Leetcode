class Solution {
public:
    long long int mod_exp(int x, int y, int mod) {
        if(y == 0)
            return 1 % mod;
        if(y==1)
            return x%mod;
        if(y%2 == 1)
            return (x%mod * mod_exp(x, y-1, mod))%mod;
        long long int half = mod_exp(x, y/2, mod)%mod;
        return (half * half)%mod;
    } 
    
    long long int mod_sub(int a, int b, int mod) {
        return (a%mod - b%mod + mod)%mod;
    }
    
    
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort Array as effective answer is the same since it is subsequences and not subarray
        long long int ans = 0;
        int mod = 1e9+7;
        for(int i=0; i<n; i++) {
            if(nums[i] * 2 <= target)
                ans = (ans+1)%mod;
            int req_min = target-nums[i];
            int n_lte = upper_bound(nums.begin(), nums.begin()+i, req_min) - nums.begin();
            int total = i;
            int non_essential = total - n_lte;
            //int essential_subsequences = mod_exp(2, n_lte, mod);
            long long int subsequences = (mod_sub(mod_exp(2, n_lte, mod), 1, mod) * mod_exp(2, non_essential, mod))%mod;
            //cout<<n_lte<<" "<<mod_sub(mod_exp(2, n_lte, mod), 1, mod)<<endl;
            ans = (ans + subsequences)%mod;
        }
        return (int)ans;
    }
};