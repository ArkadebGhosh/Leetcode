/*
Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K.
Decrease the height of the tower by K ( you can do this operation only if the height of the tower is greater than or equal to K)
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower.


Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{3, 3, 6, 8}. The difference between 
the largest and the smallest is 8-3 = 5.
*/

int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int ans = arr[n-1] - arr[0];
        for(int i = 1; i<n; i++) {
            if(arr[i]-k < 0)
            continue;
            int currlow = min(arr[0]+k, arr[i]-k);
            int currhigh = max(arr[i-1]+k, arr[n-1]-k);
            ans = min(ans, currhigh - currlow);
        }
        return ans;
    }
