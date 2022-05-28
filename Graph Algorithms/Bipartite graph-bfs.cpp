#include <bits/stdc++.h>
using namespace std;
//TC: O(N+E) ~ O(N) SC:O(N+E) + O(N) + O(N) ~~O(N)
bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src);  //src :starting node
    color[src] = 1; //initially coloured as 1
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        for(auto it : adj[node]) {  //traversing for all adjacent nodes
            if(color[it] == -1) {    //chking if adjacent node is not cloured
                color[it] = 1 - color[node]; //getting the opposite color of the one which is coloured beside cur node and then, coloring it
                q.push(it); 
            } else if(color[it] == color[node]) {    //meaning that node is already coloured& chking if adjacent nodes have same color
                return false;  //false when adjacent node and cur node are of sam colour
            }
        }
    }
    return true;  //when queue is empty
}
//if a graph has multiple components, then even if one of them is not bipartite, then the entire graph is not bipartite
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];         //acts as visited array
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {    //iterating through all nodes(used when there are multiple components)
        if(color[i] == -1) { //not been colored and not been visited
            if(!bipartiteBfs(i, adj, color)) { //if this function evaluates to false, then its not bipartite
                return false;
            }
        }
    }
    return true; 
}

