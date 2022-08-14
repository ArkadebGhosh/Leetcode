/*
Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contiguous subarray sum.


Example 1:

Input:
N = 7
arr[] = {8,-8,9,-9,10,-11,12}
Output:
22
Explanation:
Starting from the last element
of the array, i.e, 12, and 
moving in a circular fashion, we 
have max subarray as 12, 8, -8, 9, 
-9, 10, which gives maximum sum 
as 22.
Example 2:

Input:
N = 8
arr[] = {10,-3,-4,7,6,5,-4,-1}
Output:
23
Explanation: Sum of the circular 
subarray with maximum sum is 23
*/

// arr: input array
    // n: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int n){
        
        //Case 1: Find using Kadane - No wrap around
        int sum  = 0;
        int kadane = INT_MIN;
        int i;
        int high = INT_MIN;
        for(i = 0; i<n; i++) {
            sum+=arr[i];
            kadane = max(kadane, sum);
            if(sum < 0)
                sum  = 0;
        }
        //End of Case 1
        
        //Case 2: Find chain of numbers with largest negative sum - eliminate from total sum to get sum with wrap around
        // Reverse array element signs and apply Kadane to find longest chain of negative sums
        for(int i = 0; i<n; i++)
        arr[i] = arr[i] * -1;
        
        int sum2  = 0;
        int kadane2 = INT_MIN;
        for(i = 0; i<n; i++) {
            sum2 = sum2+arr[i];
            kadane2 = max(kadane2, sum2);
            if(sum2<0)
                sum2 = 0;
        }
        
        int total = 0;
        for(int i = 0; i<n;i++)
        total-=arr[i];
        // End of Case 2
        
        //Check if all elements are negative
        if(total == -1 * kadane2)
        return kadane;

        return max(kadane, total + kadane2);
    }
