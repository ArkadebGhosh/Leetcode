/*
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:

Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).

Your Task:  
You don't need to read input or print anything. Your task is to complete the function rowWithMax1s() which takes the array of booleans arr[][], n and m as input parameters and returns the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.
 

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)
*/
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int posFirst = m;
	    int ans = -1;
	    for(int j = 0; j<n; j++) {
	        if(arr[j][posFirst-1] == 0)
	        continue;
	        int pos = posFirst-1;
	        while(pos>=0 && arr[j][pos]!=0)
	        --pos;
	        posFirst = pos+1;
	        ans = j;
	    }
	    if(posFirst == m)
	    return -1;
	    return ans;
	}
