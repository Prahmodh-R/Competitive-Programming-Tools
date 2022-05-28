int vis[100005];
bool bfscycle(int node){
	queue<pair<int,int>> q;
	q.push({node,0});
	vis[node]=1;
	while(!q.empty()){
		int node=q.front().first;
		int parent=q.front().second;
		q.pop();
		for(auto it: adj[node]){
			if(vis[it]==0){
				q.push({it,node});
				vis[it]=1;
			}else if(vis[it]==true && it!=par) return true;
		}
	}
	return false;
}
void bfscycledetect(){
 bool fl=false;
 for(int i=1;i<=n;i++){
  if(vis[i]==0){
   if(bfscycle(i)==true){
   	  fl=true;
   	  break;
   }
}
}
if(fl==true) cout<<"cycle present";
else cout<<"no cycle";
}

//another code
//TC: O(N+E) ~ O(N) SC:O(N+E) + O(N) + O(N) ~~O(N)
//N is time taken for visiting N nodes, and E is for travelling through adjacent nodes overall
//space for adj list,vis array and queue
class Solution {

public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
    {
        vector<int> parent(V, -1);
     
        // Create a queue for BFS
        queue<pair<int,int>> q; //(node,parent)
     
        visited[s] = true;
        q.push({s, -1});
     
        while (!q.empty()) {
     
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
     
            for (auto it : adj[node]) {
                if (!visited[it]) {      //if not visited
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)     //node already visited, if adjacent node is not a parent node, then some traversal earlier would have visited it
                    return true;
            }
        }
        return false;
    }
public:
	bool isCycle(int V, vector<int>adj[]){     //V:total no. of nodes
	    vector<int> vis(V, 0); 
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) { //if vis[i]==false
	            if(checkForCycle(i, V, adj, vis)) return true; 
	        }
	    }
	    
	    return false; 
	}
};

 
