//link: https://www.youtube.com/watch?v=zRza99HPvkQ&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=56
#include<bits/stdc++.h>
using namespace std;
int main(){
	int W,n;  //w is the total capacity and n is the no. of objects
	cin>>W>>n;
	int wt[n];
	int val[n];
	for(int i=0;i<n;i++){  
		cin>>wt[i]>>val[i];
	}
	int dp[n+1][w+1];
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			if(i==0 or w==0){
				dp[i][w]=0;
			}
			else if(wt[i]<=W){ //if it can be picked,weight is less than capacity
				dp[i][w]=max(val[i]+dp[i-1][w-wt[i]],dp[i-1][w]);
			}//finding max of either choosing the object or leaving the object
			else{
				dp[i][w]=dp[i-1][w];  //if weight of obj >capacity
				//then we set it as the previous object's weight
			}
		}
	}
	cout<<dp[n][W];  //printing the final answer, obtained by going through
	//all n objects and all possible weights
}
EG: n=4, W=8 , val={1,2,5,6}, wt={2,3,4,5}
the dp matrix would look like
  0 1 2 3 4 5 6 7 8 - column indexes
0 0 0 0 0 0 0 0 0 0 
1 0 0 1 1 1 1 1 1 1
2 0 0 1 2 2 3 3 3 3
3 0 0 1 2 5 5 6 7 7
4 0 0 1 2 5 6 6 7 (8)

(8) is the final answer

If we wanna know which objects are included, then use the condition
while(i>0 and j>0){ //start from the last row aand move to the first row
	if(dp[i][w]==dp[i-1][w]){
		obj[i] is not included
		i--;
	}else{
		obj[i] is included;
		i--;
		j=j-wt[i];  //indicating that this obj is included, thereby reducing the remaining weight
 	}
} 
