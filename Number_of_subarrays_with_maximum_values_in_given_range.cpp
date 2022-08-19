/*
Given an array of N elements and L and R, print the number of sub-arrays such that the value of the maximum array element in that subarray is at least L and at most R.

Example 1:

Input : Arr[] = {2, 0, 11, 3, 0}
L = 1 and R = 10
Output : 4
Explanation:
The sub-arrays {2}, {2, 0}, {3} and {3, 0}
have maximum in range 1-10.


Example 2:

Input : Arr[] = {3, 4, 1}
L = 2 and R = 4
Output : 5
*/

class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        // Count subarrays containing elements less than equal to R
        long c1 = 0;
        int p1 = 0;
        for(int i = 0; i<n; i++) {
            if(a[i] > R) {
                long len = (i-p1);
                c1 += (len * (len + 1))/2;
                p1 = i+1;
            }
        }
        c1+=((long)(n-p1) * (n-p1+1))/2;
        
        //Count subarrays containing elements less than L
        long c2 = 0;
        p1 = 0;
        for(int i = 0; i<n; i++) {
            if(a[i] >= L) {
                long len = (i-p1);
                c2 += (len * (len + 1))/2;
                p1 = i+1;
            }
        }
        c2+=((long)(n-p1) * (n-p1+1))/2;
        return c1 - c2;
    }
};
