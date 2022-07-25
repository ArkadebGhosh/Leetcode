/*
Given an array of 0s and 1s, we need to write a program to find the minimum number of swaps required to group all 1s present in the array together.

Example 1:

Input : arr[ ] = {1, 0, 1, 0, 1}
Output : 1
Explanation:
Only 1 swap is required to group all 1's together. 
Swapping index 1 and 4 will give arr[] = {1, 1, 1, 0, 0}.
*/
int minSwaps(int arr[], int n) {
    int m = 0;
    int count = 0;
    for(int i = 0; i<n; i++) {
        if(arr[i] == 1)
        ++count;
    }
    if(count==0)
    return -1;
    int ptr1 = 0, ptr2=0;
    while(ptr2 < count) {
        if(arr[ptr2] == 0)
        ++m;
        ++ptr2;
    }
    
    int ans = m;
    while(ptr2 < n) {
        if(arr[ptr2] == 0)
        ++m;
        if(arr[ptr1] == 0)
        --m;
        ans = min(ans, m);
        ++ptr2;
        ++ptr1;
    }
    return ans;
}
