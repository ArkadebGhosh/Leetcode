/*
Given two Arrays A[] and B[] of length N and M respectively. Find the minimum number of insertions and deletions on the array A[], required to make both the arrays identical.
Note: Array B[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at end.

 

Example 1:

Input:
N = 5, M = 3
A[] = {1, 2, 5, 3, 1}
B[] = {1, 3, 5}
Output:
4
Explanation:
We need to delete 2 and replace it with 3.
This costs 2 steps. Further, we will have to
delete the last two elements from A to
obtain an identical array to B. Overall, it
results in 4 steps.
Example 2:
Input:
N = 2, M = 2
A[] = {1, 4}
B[] = {1, 4}
Output :
0
Explanation:
Both the Arrays are already identical.
*/


int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        unordered_set<int> hashb;
        for(int i = 0; i<M; i++) {
            if(hashb.count(B[i]));
            hashb.insert(B[i]);
        }
        int del = 0;
        vector<int> arr;
        for(int i = 0; i<N; i++) {
            if(hashb.count(A[i]))
            arr.push_back(A[i]);
            else
            ++del;
        }
        if(arr.size() == 0)
        return del + M;
        vector<int> tails;
        tails.push_back(arr[0]);
        for(int i = 1; i<arr.size(); i++) {
            if(arr[i] > tails.back()) {
                tails.push_back(arr[i]);
            }
            else {
                int lb = lower_bound(tails.begin(), tails.end(), arr[i]) - tails.begin();
                tails[lb] = arr[i];
            }
        }
        
        int add = M-tails.size();
        int del2 = arr.size() - tails.size();
        return del + add + del2;
    }
