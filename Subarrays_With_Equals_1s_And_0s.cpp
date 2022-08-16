/*
Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

Example 1:

Input:
n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,(2, 5), (0, 5), (1, 6)
Example 2:

Input:
n = 5
A[] = {1,1,1,1,0}
Output: 1
Explanation: The index range for the 
subarray is (3,4).
*/
class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        unordered_map<int, int> m; // key -> freq(1) - freq(0) till now, val -> count
        m[0] = 1;
        int ones = 0, zeroes = 0;
        long long int ans = 0;
        for(int i = 0; i<n; i++) {
            if(arr[i] == 1)
            ++ones;
            else
            ++zeroes;
            int diff = ones - zeroes;
            if(m.count(diff)) {
                ans += m[diff];
                m[diff] += 1;
            } 
            else
            m[diff] = 1;
        }
        return ans;
    }
};
