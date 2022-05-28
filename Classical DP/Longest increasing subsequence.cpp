Longest increasing subsequence
find the longest subsequence of elements which are increasing in order
intially have an array of size n, and mark all as 1 coz each is a LIS to  itself
#include<bits/stdc++.h> 
using namespace std; 
//https://www.youtube.com/watch?v=mouCn3CFpgg&list=PLEJXowNB4kPxBwaXtRO1qFLpCzF75DYrS&index=25
/* lis() returns the length of the longest increasing 
subsequence in arr[] of size n */
int lis( int arr[], int n ) 
{ 
	int lis[n]; 

	lis[0] = 1; 

	/* Compute optimized LIS values in bottom up manner */
	for (int i = 1; i < n; i++ ) 
	{ 
		lis[i] = 1; 
		for (int j = 0; j < i; j++ ) 
			if ( arr[i] > arr[j] && lis[i] <= lis[j])  //the second condition is to find the longest such subsequence
			//if we already found a longer subsequence then we do not consider the first condition if lis at the larger element is already having a longer lis value
				lis[i] = lis[j] + 1; 
	} 

	// Return maximum value in lis[] 
	return *max_element(lis, lis+n); 
} 
	
/* Driver program to test above function */
int main() 
{ 
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Length of lis is %d\n", lis( arr, n ) ); 
	return 0; 
}

IF we are asked to find the elements of the lis
keep a pointer at the max element of lis array,(say el1)
then start finding elements until we find an element that has a difference in lis 
array values of 1 (say el2), if found then put those eleents
if found, then we set current value as el2 and find the next elemnt as difference atmost 1

	TC :O(N^2)  SC: O(N)