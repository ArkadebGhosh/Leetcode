class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        //Try to make 0 to n gardens full, find corresponding max partial
        int n = flowers.size();
        sort(flowers.begin(), flowers.end());
        vector<long long> prefix(n, 0);
        prefix[0] = flowers[0];
        for(int i = 1; i<n; i++)
            prefix[i] = prefix[i-1] + flowers[i];
        long long remaining = newFlowers;
        long long maxBeauty = 0;
        int fullupto = n;
        for(int i = n; i>=1; i--) {
            if(flowers[i-1] >= target) {
                maxBeauty = max(maxBeauty, maxBeauty + full);
                fullupto = i;
                continue;
            }
            if(i<n && flowers[i] < target)
                remaining -= (target - flowers[i]);
            if(remaining < 0)
                break;
            long long low = 0;
            long long high = target - 1;
            while(low <= high) {
                long long guess = (low + high)/2;
                int modify_till = lower_bound(flowers.begin(), flowers.begin()+i, guess) - flowers.begin();
                long long required = 0;
                if(modify_till == n)
                    required = guess * n - prefix[n-1];
                else
                    required = guess * modify_till -(prefix[modify_till] - flowers[modify_till]);
                if(required > remaining)
                    high = guess - 1;
                else 
                    low = guess + 1;
            }
            maxBeauty = max(maxBeauty, (long long) (n-i) * full + high * partial);     
        }
        long long allfull = 0;
        for(auto &it: flowers) {
            if(it >= target)
                break;
            allfull += (target - it);
        }
        if(allfull <= newFlowers)
            return max(maxBeauty, (long long)n * full);
        return maxBeauty;
    }
};