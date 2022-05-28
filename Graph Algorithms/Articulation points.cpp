#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<int> &isArticulation) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++;
    int child = 0; //used to count independent children nodes for the root node
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {   //if adj node is unvisited
            dfs(it, node, vis, tin, low, timer, adj, isArticulation); 
            low[node] = min(low[node], low[it]); 
	     
            if(low[it] >= tin[node] && parent != -1) { //we have found an articulation pt
                isArticulation[node] = 1; 
            }
            child++; //used to count independent children
        } else {  //if the adj node is already visited
            low[node] = min(low[node], tin[it]); //will simply be the time of insertion
        }
    } //dfs call for all adj nodes are completed
    
    if(parent == -1 && child > 1) {   //if it's the first node(chk for the first node)
        isArticulation[node] = 1; 
    }
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0);
	vector<int> isArticulation(n, 0);  //hash array to print the articualtion points only once
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) { //if node is unvisited
	        dfs(i, -1, vis, tin, low, timer, adj, isArticulation); 
	    }
	}
	
	for(int i = 0;i<n;i++) {  //printing all the articulation points in the given graph
	    if(isArticulation[i] == 1) cout << i << endl;
	}
	
	return 0;
}   //TC :O(N+E)  SC:O(N)

