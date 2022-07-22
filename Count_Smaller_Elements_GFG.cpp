/*
Given an array Arr of size N containing positive integers. Count number of smaller elements on right side of each array.

Example 1:

Input:
N = 7
Arr[] = {12, 1, 2, 3, 0, 11, 4}
Output: 6 1 1 1 0 1 0
Explanation: There are 6 elements right
after 12. There are 1 element right after
1. And so on.
*/


struct ele {
    int val;
    int index;
    int count;
};

class Solution{
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	    vector<ele> A;
	    for(int i = 0; i<n; i++) 
	        A.push_back({arr[i], i, 0});
	        
	    vector<int> index_data(n, 0);
	    mergesort(A, 0, n-1);
	    
	    for(int i = 0; i<n; i++)
	        index_data[A[i].index] = A[i].count;
	        
	    return index_data;
	}
	
	void mergesort(vector<ele> &arr, int low, int high) {
	    int mid = (low+high)/2;
	    if(low >= high)
	    return;
	    mergesort(arr, low, mid);
	    mergesort(arr, mid+1, high);
	    vector<ele> left(arr.begin()+low, arr.begin()+mid+1);
	    vector<ele> right(arr.begin()+mid+1, arr.begin()+high+1);
	    int ln = left.size();
	    int rn = right.size();
	    int arrptr = low;
	    int rightptr = 0;
	    for(int i = 0; i<ln; i++) {
	        left[i].count += rightptr;
	        while(rightptr<rn && right[rightptr].val < left[i].val) {
	            left[i].count+=1;
	            arr[arrptr++] = right[rightptr++];
	        }
	        arr[arrptr++] = left[i];
	    }
	    while(rightptr<rn)
	        arr[arrptr++] = right[rightptr++];
	}
};
