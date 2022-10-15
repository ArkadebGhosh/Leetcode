class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1 = 0, s2 = 0;
        for(auto &num1: nums1) 
            s1 += num1;
        
        for(auto &num2: nums2) 
            s2 += num2;        
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        if(s1 > s2) {
            nums1.swap(nums2);
            swap(s1, s2);
        }
        int p1 = 0;
        int p2 = nums2.size()-1;
        int opr = 0;
        while(s1 < s2) {
            if(p2<0 || p1<nums1.size() && p2>=0 && 6 - nums1[p1] > nums2[p2] - 1) {
                s1 += (6 - nums1[p1]);
                ++opr;
                ++p1;
            }
            else if(p1 >= nums1.size() || p1<nums1.size() && p2>=0) {
                s2 -= (nums2[p2] - 1);
                ++opr;
                --p2;
            }
            if(s1 >= s2)
                return opr;
            else if(p1 == nums1.size() && p2 == -1)
                return -1;
        }
        return 0;
    }
};