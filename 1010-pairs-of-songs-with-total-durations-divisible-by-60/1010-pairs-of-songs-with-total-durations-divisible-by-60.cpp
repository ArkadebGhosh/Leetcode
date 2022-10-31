class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> rem(60, 0);
        for(int i = 0; i<time.size(); i++) {
            int mod = time[i]%60;
            rem[mod]++;
        }
        long long int ans = 0;
        
        for(int i = 1; i<=29; i++) {
            ans += ((long long int)rem[i] * rem[(60-i) % 60]);
        }
        
        ans += ((long long int)rem[0] * (rem[0] - 1))/2;
        ans += ((long long int)rem[30] * (rem[30] - 1))/2;
        return (int)ans;
    }
};