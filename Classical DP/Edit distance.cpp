Edit distance prob
Its a method to find out how dissimilar two strings are ,
by counting the minimum no. of operations required to convert one string
to another
The operations allowed would be given
mainly they would be any combination of insertion/deletion/substitiution

edge cases:
if(s1.len()==0){
	ans=s2.len();  //insert operations only
}
if(s2.len()==0){
	ans=s1.len();   //delete operation only
}

Possible cases : if the characters at both indexes is the same,
We go from right to left int he strings
have two pointers i(for s1) and j(for s2)
if both s1[i] and s2[j] are matching, then do i-- and j--
	and dp[i][j]=dp[i-1][j-1]+0

If the characters at both the indexes are not matching
then if we wanna insert a character, then we always do that to the right of the current 
character
dp[i][j] =dp[i][j-1] + 1  //if we're inserting
we decrement i by one

If we are removing a char then we decrement i, dp[i][j]=dp[i-1][j]+1
If we wanna replace characters, dp[i][j]=dp[i-1][j-1]+1
decrement both i and j
The optimal operation would be to find the minimum of insert,delete and replace operations

Create a dp matrix of size, dp[m+1][n+1], m: size of s1, n=size of s2
mark all the first row elements as 0,1,2,...n  coz it would take those many 
characters to be included 
mark all the first column elements as 0,1,...m coz if s2 is emepty, then we can only delete
elements in s1
answer is dp[m][n]

TC : O(M*N)
SC : O(M*N)

// A Dynamic Programming based C++ program to find minimum 
// number operations to convert str1 to str2 
#include <bits/stdc++.h> 
using namespace std; 

// Utility function to find the minimum of three numbers 
int min(int x, int y, int z) 
{ 
	return min(min(x, y), z); 
} 

int editDistDP(string str1, string str2, int m, int n) 
{ 
	// Create a table to store results of subproblems 
	int dp[m + 1][n + 1]; 

	// Fill d[][] in bottom up manner 
	for (int i = 0; i <= m; i++) { 
		for (int j = 0; j <= n; j++) { 
			// If first string is empty, only option is to 
			// insert all characters of second string 
			if (i == 0) 
				dp[i][j] = j; // Min. operations = j 

			// If second string is empty, only option is to 
			// remove all characters of FIRST string 
			else if (j == 0) 
				dp[i][j] = i; // Min. operations = i 

			// If last characters are same, ignore last char 
			// and recur for remaining string 
			else if (str1[i - 1] == str2[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1]; 

			// If the last character is different, consider all 
			// possibilities and find the minimum 
			else
				dp[i][j] = 1 + min(dp[i][j - 1], // Insert 
								dp[i - 1][j], // Remove 
								dp[i - 1][j - 1]); // Replace 
		} 
	} 

	return dp[m][n]; 
} 

// Driver program 
int main() 
{ 
	// your code goes here 
	string str1 = "sunday"; 
	string str2 = "saturday"; 

	cout << editDistDP(str1, str2, str1.length(), str2.length()); 

	return 0; 
} 