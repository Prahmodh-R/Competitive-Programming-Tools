//Brute force approach
#include<bits/stdc++.h>
using namespace std;
//TC:O(N^2)  SC: O(3*N)
int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  

    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)      //coz we need n-1 edges in mst
    { 
        
        int mini = INT_MAX, u; 
  
        for (int v = 0; v < N; v++)  //0-based indexing
            if (mstSet[v] == false && key[v] < mini)  //finding minimum key value
                mini = key[v], u = v; 
                
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {    //iterating for adj nodes
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) //if not present in mst and chking if its lesser weight 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}

//Efficient approach
//TC:O(NLOGN) + O(N+E)  ~ O(NLOGN)  SC:O(3*N)
int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});  //we store (key[index],index) in priority queue 
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 
    while(!pq.empty()) //O(N+E)
    { 
        int u = pq.top().second; //the index that has the minimum value is being stored in u taken from pr queue
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {     
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		
                pq.push({key[v], v});    
                key[v] = weight; 
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}
