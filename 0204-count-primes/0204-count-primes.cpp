class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n+1, true);
        for(int i = 2; i*i<=n; i++) {
            if(primes[i] == true) {
                for(int j = i*i; j<=n; j+=i) {
                    primes[j] = false;
                }
            }
        }
        int c = 0;
        for(int i = 2; i<n; i++) {
            if(primes[i])
                ++c;
        }
        return c;
    }
};