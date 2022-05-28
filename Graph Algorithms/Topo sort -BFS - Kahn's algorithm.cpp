#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0);  //assuming graph is 0-based
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {  //an adjacent node means there is a node being directed to the current node, so we increment the degree of that node
	            indegree[it]++;  //calculating how many nodes are incoming to the adjacent ndoe
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo;     //storing the topo sort
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node)
	        for(auto it : adj[node]) {  //traversing for all it's adjacent nodes
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
};

