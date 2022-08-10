/*
Given an array A[] of N integers and replace every element with the least greater element on its right side in the array. If there are no greater elements on the right side, replace it with -1. 

Example 1:

Input:
A[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28}
Output: {18, 63, 80, 25, 32, 43, 80, 93, 80, 25, 93, -1, 28, -1, -1}
Explanation: 
The least next greater element of 8 is 18.
The next greater element of 58 is 63 and so on.

Example 2:

Input:
A[] = {2, 6, 9, 1, 3, 2}
Output: {3, 9, -1, 2, -1, -1}
*/

vector<int> findLeastGreater(vector<int>& arr, int n) {
        set<int> s;
        vector<int> ans(n, -1);
        for(int i = n-1; i>=0; i--) {
            auto lge_ptr = s.upper_bound(arr[i]);
            if(lge_ptr != s.end())
            ans[i] = *lge_ptr;
            s.insert(arr[i]);
        }
        return ans;
    }
