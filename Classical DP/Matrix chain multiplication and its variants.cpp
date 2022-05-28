Matrix chain multiplication and its variants
If we are to minimize the value by division of elements in the array
,then the code goes like
Recursive soln:
int mcm(int arr[],int l,int r,int n){
	if(l<0 or l>=n or r<0 or r>=n){  //boundary check
		return -1;
	}
	int ans=INT_MAX;  ///coz we are minimizing the answer
	for(int i=l;i<r;i++){
		int left=mcm(arr,l,i,n);
		int right=mcm(arr,i+1,r,n);
		ans=min(left,right);
	}
	return ans;
}

int mcm(int arr[],int l,int r){  //TC: exponential
	if(l>=r){
		return 0;
	}
	int res=INT_MAX;  //since we wanna minimize the answer
	int temp;
	for(int k=l;k<r;k++){
		temp=mcm(arr,l,k)+mcm(arr,k+1,r)+arr[l]*arr[k]*arr[r];
		res=min(res,temp);
	}
	return res;
}

//USING MEMOIZATION  TC :O(N^3)
//We initialize the mem matrix as -1 for every value, since we know that -1 can never be an answer
if(mem[l][r]!=-1){

}
store mem[l][r]=res;

DP solution:
The first matrix will have operations=0 coz multiplication
cant be done with a single matrix
We need to find the no. of operations for all subproblems
of size i to build the solution for subproblems of size i+1
We'll start with size 2 and keep solving until we get solution for size need
The size of the dp table will be n*n
mark dp[1][1], dp[2][2],dp[3][3]... will be marked zero, coz they are subproblems
of size 1
arr[l-1]*arr[partition pt]*arr[r] needs to be added

for(cl=2;cl<=(n-1);cl++){
	for(l=1;l<=(n-1);l++){
		r=(l+cl-1);
		dp[l][r]=INT_MAX; //coz we wanna minimize the value
		for(k=l;k<r;k++){  //partitioning at the k'th position
			total=dp[l][k]  + dp[k+1][r] + arr[l-1]*arr[k]*arr[r];
			dp[l][r]=min(dp[l][r],total);
		}       left matrix  right marix
	}
}
return dp[1][n-1];  //will store the final answer