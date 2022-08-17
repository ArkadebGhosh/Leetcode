/*
Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.If it cannot reach the target position return -1.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

Example 1:

Input:
N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3
*/

class Solution {
public:
    struct Node{
        int x;
        int y;
        int dis;
    };
    
    bool isSafe(int x, int y, int N) {
        if(x<1 || x>N || y<1 || y>N)
        return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    vector<vector<int>> visited(N+1, vector<int> (N+1, false));
	    
	    queue<Node> q;
	    q.push({KnightPos[0], KnightPos[1], 0});
	    
	    if(KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1])
	    return 0;
	    
	    vector<int> dx = {2, 2, 1, -1, -2, -2, 1, -1};
	    vector<int> dy = {-1, 1, 2, 2, -1, 1, -2, -2};
	    while(!q.empty()) {
	        int currx = q.front().x;
	        int curry = q.front().y;
	        int currdis = q.front().dis;
	       // cout<<currx<<" "<<curry<<" "<<currdis<<endl;
	        for(int i = 0; i<8; i++) {
	            if(isSafe(currx+dx[i], curry+dy[i], N) && !visited[currx+dx[i]][curry+dy[i]]) {
	                visited[currx+dx[i]][curry+dy[i]] = true;
	                if(currx+dx[i] == TargetPos[0] && curry + dy[i] == TargetPos[1])
	                return currdis+1;
	                q.push({currx+dx[i], curry+dy[i], currdis+1});
	            }
	        }
	        q.pop();
	    }
	    return -1;
	}
};
