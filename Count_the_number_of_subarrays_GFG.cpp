/*
Given an array A[] of N integers and a range(L, R). The task is to find the number of subarrays having sum in the range L to R (inclusive).

Example 1:

Input:
N = 3, L = 3, R = 8
A[] = {1, 4, 6}
Output: 
3
Explanation: 
The subarrays are [1,4], [4] and [6]
Example 2:

Input:
N = 4, L = 4, R = 13
A[] = {2, 3, 5, 8}
Output: 
6
Explanation: 
The subarrays are [2,3], [2,3,5], 
[3,5],[5], [5,8] and [8]
*/


long long countSubarray(int N,vector<int> A,long long L,long long R) {
        return (sumlte(A, N, R) - sumlte(A, N, L-1));
    }
    
    long long int sumlte(vector<int> &arr, int n, long long t) {
        long long int sum = 0, start = 0, subarrays = 0;
        for(int i = 0; i<n; i++) {
            sum+=arr[i];
            if(sum<=t) {
                subarrays+=(i-start+1);
            }
            else {
                while(sum > t) {
                    sum-=arr[start];
                    start++;
                    if(sum <= t)
                    subarrays += (i-start+1);
                }
            }
        }
        return subarrays;
    }
