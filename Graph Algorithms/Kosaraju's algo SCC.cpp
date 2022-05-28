#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) { //implementation of topo sort
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
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
	}
	
	stack<int> st;
	vector<int> vis(n, 0); 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	
	vector<int> transpose[n]; 
	
	for(int i = 0;i<n;i++) {
	    vis[i] = 0;  //remarking visited as zero, so that while implementing revdfs, we can mark it visited then
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i); //reversing the edges(from adj_node - cur_node)
	    }
	}
	
	
	
	while(!st.empty()) { //printing all nodes of SCC
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) {    //if node is not visited
	        cout << "SCC: "; 
	        revDfs(node, vis, transpose); 
	        cout << endl; 
	    }
	}
	
	
	return 0;
}

