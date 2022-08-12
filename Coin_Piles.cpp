/*
There are N piles of coins each containing  Ai (1<=i<=N) coins. Find the minimum number of coins to be removed such that the absolute difference of coins in any two piles is at most K.
Note: You can also remove a pile by removing all the coins of that pile.


Example 1:

Input:
N = 4, K = 0
arr[] = {2, 2, 2, 2}
Output:
0
Explanation:
For any two piles the difference in the
number of coins is <=0. So no need to
remove any coins. 
Example 2:
Input:
N = 6, K = 3
arr[] = {1, 5, 1, 2, 5, 1} 
Output :
2
Explanation:
If we remove one coin each from both
the piles containing 5 coins , then
for any two piles the absolute difference
in the number of coins is <=3. 

*/

int minSteps(int A[], int N, int K) {
        // code here
        sort(A, A+N);
        vector<int> prefix(N+1, 0);
        for(int i = 1; i<=N; i++)
        prefix[i] = prefix[i-1]+A[i-1];
        int ans = INT_MAX;
        //Treat A[i] as minimum , erase all piles before A[i], corresponding max = A[i]+k, reduce all piles with val >= A[i]+k+1 to A[i]+k
        for(int i = 0; i<N; i++) {
            int maxPos = upper_bound(A, A+N, A[i]+K) - A;
            ans = min(ans, prefix[i] + prefix[N] - prefix[maxPos] - (N - maxPos) * (A[i] + K));
        }
        return ans;
    }
