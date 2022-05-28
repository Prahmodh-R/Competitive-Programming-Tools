#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: adj[node]) {     //traversing for all adj nodes
        if(it == parent) continue; //if its for the parent, we are going backward, which we dont wanna do
        //low[node] keeps track of only the visited node and the other adj. nodes. we avoid going back to parent node, to prevent waste of time
        if(!vis[it]) { //for any other adj node which isnt visited so far
            dfs(it, node, vis, tin, low, timer, adj); 
            low[node] = min(low[node], low[it]); //updating low[node] when dfs is complete :either itself or adj's low
            if(low[it] > tin[node]) {
                cout << node << " " << it << endl;   //indicating a bridge
            }
        } else { //if node is visited and dfs for adj node is noot done
            low[node] = min(low[node], tin[it]); //low[node] will simply be the time of insertion when node is visited
        }
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
	int timer = 0; //initial time
	for(int i = 0;i<n;i++) { //dfs code when there are multiple components
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj);  //root node has parent -1
	    }
	}
	
	return 0;
}
