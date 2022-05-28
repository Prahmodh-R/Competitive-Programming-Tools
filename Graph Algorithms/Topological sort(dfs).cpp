#include <bits/stdc++.h>
using namespace std;
TC:O(N+E), SC: O(N) + O(N)
class Solution{
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; 
        
        for(auto it : adj[node]) {  //traversing adjacent nodes
            if(!vis[it]) {  //if adj node is not visited
                findTopoSort(it, vis, st, adj); 
            }
        }
        st.push(node);  //pushing onto stack after recursive cll for a node is over
    }
	public:
	vector<int> topoSort(int N, vector<int> adj[]) {
	    stack<int> st; 
	    vector<int> vis(N, 0); 
	    for(int i = 0;i<N;i++) {
	        if(vis[i] == 0) {      //(whichever node is not visited)
	            findTopoSort(i, vis, st, adj); 
	        }
	    }
	    vector<int> topo;
	    while(!st.empty()) {
	        topo.push_back(st.top()); 
	        st.pop(); 
	    }
	    return topo; 
	    
	}
};
