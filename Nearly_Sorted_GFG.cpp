/*
Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

Example 1:

Input:
n = 7, k = 3
arr[] = {6,5,3,2,8,10,9}
Output: 2 3 5 6 8 9 10
Explanation: The sorted array will be
2 3 5 6 8 9 10
Example 2:

Input:
n = 5, k = 2
arr[] = {3,1,4,2,5}
Output: 1 2 3 4 5 
*/

class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<=k; i++)
        pq.push(arr[i]);
        vector<int> sorted;
        int ptr = k+1;
        while(ptr<n) {
            sorted.push_back(pq.top());
            pq.pop();
            pq.push(arr[ptr]);
            ++ptr;
        }
        while(!pq.empty()) {
            sorted.push_back(pq.top());
            pq.pop();
        }
        return sorted;
    }
};
