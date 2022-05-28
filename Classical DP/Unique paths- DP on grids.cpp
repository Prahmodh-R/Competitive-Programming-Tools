Unique paths- DP on grids
//https://leetcode.com/problems/unique-paths/
given a grid of size m*n, we need to find the no. of unique ways to reach m,n from (0,0) 
The operations allowed are right and up
We find no. of ways to reach (0,0) from 

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 or j==0){
                    dp[i][j]=1;  //there would only be one way(either going up or left)
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]; //sum of the ways by which we can reach the destination by going up or left
                }
            }
        }
        return dp[m-1][n-1];
    }
};