class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int total = l1+l2;
        int start = 0;
        int end = l1;
        double ans;
        while(start<=end) {
            int p1 = (start+end+1)/2;
            int p2 = (total+1)/2 - p1;
            if(p2 > l2) {
                start = p1;
                continue;
            }
            if(p2 < 0) {
                end = p1 - 1;
                continue;
            }
            int lp1 = (p1 <= 0) ? INT_MIN : nums1[p1-1];
            int rp1 = (p1 >= l1) ? INT_MAX : nums1[p1];
            int lp2 = (p2 <= 0) ? INT_MIN : nums2[p2-1];
            int rp2 = (p2 >= l2) ? INT_MAX : nums2[p2];
            if(lp1<=rp2 && lp2 <= rp1) {
                if(total % 2 == 1)
                    ans = max(lp1, lp2);
                else
                    ans = (double)(max(lp1,lp2) + min(rp1, rp2)) / 2;
                break;
            }            
            else if(lp2 > rp1) 
                start = p1;            
            else if(lp1 > rp2) 
                end = p1 - 1;            
        }
        return ans;
    }
};