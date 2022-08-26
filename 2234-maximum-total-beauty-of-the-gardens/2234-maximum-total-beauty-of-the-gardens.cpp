class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        //Try to make 0 to n gardens full, find corresponding max partial
        int n = flowers.size();
        sort(flowers.begin(), flowers.end());
        // for(auto &it: flowers)
        //     cout<<it<<" ";
        // cout<<endl;
        vector<long long> prefix(n, 0);
        prefix[0] = flowers[0];
        for(int i = 1; i<n; i++)
            prefix[i] = prefix[i-1] + flowers[i];
        long long remaining = newFlowers;
        long long maxBeauty = 0;
        int fullupto = n;
        // cout<<newFlowers<<" "<<target<<" "<<full<<" "<<partial<<endl;
        for(int i = n; i>=1; i--) {
            if(flowers[i-1] >= target) {
                maxBeauty = max(maxBeauty, maxBeauty + full);
                fullupto = i;
                continue;
            }
            if(i<n && flowers[i] < target)
                remaining -= (target - flowers[i]);
            // cout<<"*************************************"<<endl;
            // cout<<i<<" "<<maxBeauty<<" "<<flowers[i]<<endl;
            if(remaining < 0)
                break;
            // Guess for max partial value
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
                // cout<<guess<<" "<<modify_till<<" "<<required<<" "<<remaining<<endl;
                if(required > remaining) {
                    high = guess - 1;
                }
                else {
                    low = guess + 1;
                }
            }
            // cout<<"Max partial: "<<high<<endl;
            maxBeauty = max(maxBeauty, (long long) (n-i) * full + high * partial);      
            // cout<<"MaxBeauty: "<<maxBeauty<<endl;
        }
        long long allfull = 0;
        for(int i = 0; i<flowers.size(); i++) {
            if(flowers[i] >= target)
                break;
            allfull += (target - flowers[i]);
        }
        if(allfull <= newFlowers)
            return max(maxBeauty, (long long)n * full);
        return maxBeauty;
    }
};