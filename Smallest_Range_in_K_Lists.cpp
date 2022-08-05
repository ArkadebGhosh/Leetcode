/*
Given K sorted lists of integers, KSortedArray[] of size N each. The task is to find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, return the first such range found.

Example 1:

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.
Example 2:

Input:
N = 4, K = 3
KSortedArray[][] = {{1 2 3 4},
                    {5 6 7 8},
                    {9 10 11 12}}
Output: 4 9
Your Task :

Complete the function findSmallestRange() that receives array , array size n and k as parameters and returns the output range (as a pair in cpp and array of size 2 in java and python)

Expected Time Complexity : O(n * k *log k)
Expected Auxilliary Space  : O(k)
*/
pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
          vector<int> ptr(k, 0);
          int low = INT_MAX;
          int high = -1;
          for(int i = 0; i<k; i++) {
              pq.push({KSortedArray[i][0], i});
              high = max(high, KSortedArray[i][0]);
              low = min(low, KSortedArray[i][0]);
          }
          
          int currhigh = high;
          int currlow = low;
          
          while(true) {
              if(currhigh - currlow < high - low) {
                  low = currlow;
                  high = currhigh;
              }
              int ptrtomin = pq.top().second;
              ptr[ptrtomin]++;
              if(ptr[ptrtomin] == n)
              break;
              pq.pop();
              pq.push({KSortedArray[ptrtomin][ptr[ptrtomin]], ptrtomin});
              currlow = pq.top().first;
              currhigh = max(currhigh, KSortedArray[ptrtomin][ptr[ptrtomin]]);
          }
          return {low, high};
    }
