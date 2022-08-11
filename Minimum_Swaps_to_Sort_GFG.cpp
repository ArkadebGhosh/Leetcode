/*
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.
*/

	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    map<int,int> m;
	    for(int i  = 0; i<nums.size(); i++)
	    m[nums[i]] = i;
	    int swaps = 0, i = 0;
	    auto it = m.begin();
	    while(i<nums.size()) {
	        if(m[(*it).first] != i) {
	            int temp = m[(*it).first];
	            m[(*it).first] = i;
	            m[nums[i]] = temp;
	            swap(nums[i], nums[temp]);
	            ++swaps;
	        }
	        ++i;
	        ++it;
	    }
	    return swaps;
	}
