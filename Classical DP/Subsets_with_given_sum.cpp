int dp[n+1][s+1]; 
n: no. of ele in array
s: required sum
fill all the values in the first column as 1, since only the empty subset is a valid answer for sum 0
mark the first row completely with 0 as there is no way of picking a zero value and getting sum 
as non zero
//https://www.youtube.com/watch?v=MqYLmIzl8sQ&list=PLEJXowNB4kPxBwaXtRO1qFLpCzF75DYrS&index=11
TC : O(N*S)  ,sum=S
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		if(a[i-1]>j){
			dp[i][j]=dp[i-1][j]; //setting it to the previous row's value as we are excluding it
		}else if(a[i-1]<=j){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
		}            (excluding)     (including)
	}
}
cout<<dp[n][s];
