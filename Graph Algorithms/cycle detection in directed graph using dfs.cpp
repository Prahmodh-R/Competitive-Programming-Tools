#include<bits/stdc++.h>
using namespace std;
TC: O(N+E), E:no. of edges   SC:O(2N) +O(N)-Auxillary stack space for recursion
class Solution {
private:
    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsVis[]) {
        vis[node] = 1; 
        dfsVis[node] = 1; 
        for(auto it : adj[node]) {    //'it' refers to the adjacent node
            if(!vis[it]) { //if the adjacent node has not been visited yet
                if(checkCycle(it, adj, vis, dfsVis)) return true;
            } else if(dfsVis[it]) {//which means the adjacent node is visited in visited array, and now chking if it's visited in dfs array
                return true; 
            }
        }
        dfsVis[node] = 0; //when recursive call is over,we set dfsvis[node]=0 while returning
        return false;
    }
public:
	bool isCyclic(int N, vector<int> adj[]) {
	   int vis[N], dfsVis[N]; 
	   memset(vis, 0, sizeof vis); 
	   memset(dfsVis, 0, sizeof dfsVis); 
	   
	   for(int i = 0;i<N;i++) {   //assuming nodes are 0-based 
	       if(!vis[i]) {
	           // cout << i << endl; 
	           if(checkCycle(i, adj, vis, dfsVis)) {
	               return true; 
	           }
	       }
	   }
	   return false; 
	}
};
