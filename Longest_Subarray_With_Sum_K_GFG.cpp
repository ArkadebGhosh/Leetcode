/*
Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

 

Example 1:
 

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Example 2:

Input : 
A[] = {-1, 2, 3}
K = 6
Output : 0

*/
int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<long long int, int> sums;
        sums[0] = -1;
        long long int sum = 0;
        int ans = 0;
        for(int i = 0; i<N; i++) {
            sum+=A[i];
            if(!sums.count(sum))
            sums[sum] = i;
            if(sums.count(sum - K)) 
                ans = max(ans, i-sums[sum - K]);
        }
        return ans;
    } 
