/*
Smaller on Left
MediumAccuracy: 48.26%Submissions: 15963Points: 4
Given an array arr[ ] of N positive integers, the task is to find the greatest element on the left of every element in the array which is strictly smaller than itself, if this element does not exist for an index print "-1".

Example 1:

Input:
N = 5
arr[] = {2, 3, 4, 5, 1}
Output: 
-1 2 3 4 -1
Explanation:
Greatest element on the left of 3 smaller 
than itself is 2, for 4 it is 3 and for 5 
it is 1. Since 2 is the first element and 
no element on its left is present, so it's 
greatest smaller element will be -1 and for 
1 no element smaller than itself is present 
on its left, so it's greatest smaller element 
is -1.
*/
vector<int> Smallestonleft(int arr[], int n)
{
    // Complete the function
    set<int> s;
    vector<int> ans(n, -1);
    for(int i = 0; i<n; i++) {
        s.insert(arr[i]);
        auto it = s.lower_bound(arr[i]);
        if(it != s.begin() && it!=s.end())
        ans[i] = *(--it);
    }
    return ans;
}
