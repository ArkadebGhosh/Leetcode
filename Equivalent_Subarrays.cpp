/*
Given an array arr[] of n integers. Count the total number of sub-array having total distinct elements same as that of total distinct elements of the original array.

Example 1:

Input:
N=5
arr[] = {2, 1, 3, 2, 3} 
Output: 5
Explanation:
Total distinct elements in array is 3
Total sub-arrays that satisfy the condition
are:
Subarray from index 0 to 2
Subarray from index 0 to 3
Subarray from index 0 to 4
Subarray from index 1 to 3
Subarray from index 1 to 4

Example 2:

Input:
N=5
arr[] = {2, 4, 4, 2, 4} 
Output: 9
*/

class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_map<int, int> hash;
        for(int i  = 0; i<n; i++) {
            hash[arr[i]]+=1;
        }
        int k = hash.size();
        hash.clear();
        int start = 0, ans = 0;
        for(int i = 0; i<n; i++) {
            hash[arr[i]]+=1;
            while(hash.size() == k) {
                ans+=(n-i);
                hash[arr[start]] -= 1;
                if(hash[arr[start]] == 0) {
                    hash.erase(arr[start]);
                }
                ++start;
            }
        }
        return ans;
    }
};
