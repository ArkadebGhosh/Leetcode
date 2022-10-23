class NumArray {
public:
    vector<int> arr;
    vector<int> seg;
    int size;
    int arrsize;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arrsize = n;
        size = 4*n;
        seg = vector<int>(size, INT_MIN);
        arr = nums;
        
        // for(int i = 0; i<arrsize; i++)
        //     cout<<arr[i]<<" ";
        // cout<<endl;
        
        buildtree(seg, arr, 0, 0, arrsize-1);
        
        // for(int i = 0; i<size; i++)
        //     cout<<seg[i]<<" ";
        // cout<<endl;
    }
    
    int buildtree(vector<int> &seg, vector<int> &arr, int root, int left, int right) {
        if(left == right) {
            // cout<<root<<" "<<left<<" "<<arr[left]<<endl;
            seg[root] = arr[left];
        }
        else {
            int mid = (left + right)/2;
            seg[root] = buildtree(seg, arr, 2*root+1, left, mid) + buildtree(seg, arr, 2*root+2, mid+1, right);
        }
        return seg[root];
    }
    
    void update(int index, int val) {
        int diff = val - arr[index];
        arr[index] = val;
        updatetree(seg, diff, index, 0, 0, arrsize-1);
        // for(int i = 0; i<size; i++)
        //     cout<<seg[i]<<" ";
        // cout<<endl;
    }
    
    void updatetree(vector<int> &seg, int diff, int index, int root, int left, int right) {
        if(left > right)
            return;
        int mid = (left + right)/2;
        if(index < left || index > right)
            return;
        
        seg[root]+=diff;
        if(left == right)
            return;
        updatetree(seg, diff, index, 2*root+1, left, mid);
        updatetree(seg, diff, index, 2*root+2, mid+1, right);
    }
    
    int sumRange(int left, int right) {
        return findRoot(0, left, right, 0, arrsize-1);
    }
    
    int findRoot(int root, int left, int right, int low, int high) {
        // cout<<root<<" "<<left<<" "<<right<<" "<<low<<" "<<high<<endl;
        if(root >= size)
            return 0;
        if(left <= low && right >= high) {
            return seg[root];
        }
        else if(right < low || left > high) {
            return 0;
        }
        else {
            int leftchild = 2*root+1;
            int rightchild = 2*root+2;
            int mid = (low + high)/2;
            return findRoot(leftchild, left, right, low, mid) + findRoot(rightchild, left, right, mid+1, high);
        }
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */