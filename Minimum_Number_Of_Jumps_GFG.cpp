    int minJumps(int arr[], int n){
        // Your code here
        int start = 0;
        int limit = arr[0], newlimit = arr[0];
        int jumps = 1;
        if(n==1)
        return 0;
        if(limit == 0)
        return -1;
        if(limit >= n-1)
        return 1;
        int i = 1;
        while(i<=limit) {
            newlimit = max(newlimit, i+arr[i]);
            if(newlimit >= n-1)
            return jumps+1;
            if(i == limit && newlimit>limit) {
                limit = newlimit;
                jumps+=1;
            }
            else if(i == limit && newlimit<=limit)
            return -1;
            i++;
        }
        return jumps;
    }
