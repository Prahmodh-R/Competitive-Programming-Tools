Rod cutting prob
For each integer length, we have two choices,w e eitherc ut the 
current rod or skip cutting
Assume we cut the rod from left to right
We nned to cut either agt 0 or n, bcoz both cove rthe same case of
not cutting the rod
final profit depends on the final lengths of the subrods
after cutting and not on the order of cutting coz profits are added
based on correspinding piece for length of rods
Each item can be cut any number of times , so its simialr to unbounded knapsack
//https://www.youtube.com/watch?v=nYJDp0Hj7M4&list=PLEJXowNB4kPxBwaXtRO1qFLpCzF75DYrS&index=16

We have 2 arrays: length[],price[];

Using recursion:  TC :O(2^N)
for(i=0->n-1){
	maxval=max(maxval    ,   price[i]+func(n-i-1));
}            not cutting     price of current division length+recursive call, for remaining length
base case:
if(n<=0){
	return 0;
}

Using DP: (recursive dp)   TC : O(N * maxlen)   
max[n+1][maxlen+1];  //maxlen is capacity(length) given
int rod(int price[],int length[],int maxlen,int n){ //n is the intial length of the array length/price
	if(n==0 or maxlen==0){  //basecase
		return 0;
	}
	if(length[n-1] > maxlen){  //exclusion case
		max[n][maxlen]=rod(price,length,maxlen,n-1);
	}else{
		max[n][maxlen]=max(price[n-1]+rod(price,length,maxlen-length[n-1],n),rod(price,length,maxlen,n-1));
																		  n is taken as a whole coz recursive call is applied even to the sublength
	}
	return max[n][len];
}