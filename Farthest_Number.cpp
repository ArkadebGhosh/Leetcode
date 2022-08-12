/*
Given an array Arr[] of size N. For every element in the array, the task is to find the index of the farthest element in the array to the right which is smaller than the current element. If no such number exists then print -1.
Note: 0 based indexing.


Example 1:

Input: 
N=5
Arr[] = {3, 1, 5, 2, 4}
Output: 
3 -1 4 -1 -1
Explanation:
Arr[3] is the farthest smallest element
to the right of Arr[0].
Arr[4] is the farthest smallest element
to the right of Arr[2].
And for the rest of the elements, there is
no smaller element to their right.
*/

class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> Arr){
        //code here
        vector<int> suffix(N, Arr[N-1]);
        for(int i = N-2; i>=0; i--)
        suffix[i] = min(suffix[i+1], Arr[i]);
        vector<int> ans(N, -1);
        for(int i = 0; i<N-1; i++) {
            int idx = lower_bound(suffix.begin()+i+1, suffix.end(), Arr[i]) - suffix.begin();
            if(idx < i+1)
            continue;
            if(idx <N && suffix[idx] >= Arr[i] && idx!=0 && idx-1 > i)
            ans[i] = idx-1;
            else if(idx == N && idx - 1 > i)
            ans[i] = idx-1;
        }
        return ans;
    }
};
