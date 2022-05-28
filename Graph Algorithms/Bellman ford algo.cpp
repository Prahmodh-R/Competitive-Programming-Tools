#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }

    int src;
    cin >> src; 


    int inf = 10000000; 
    vector<int> dist(N, inf); 

    dist[src] = 0; 

    for(int i = 1;i<=N-1;i++) {  //relaxation for n-1 times
        for(auto it: edges) {  //iterating for every edge
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {   //one more relaxation to detect negative cycle
        if(dist[it.u] + it.wt < dist[it.v]) {  //if we find a reduction in the shortest distance
            cout << "Negative Cycle"; 
            fl = 1; 
            break; 
        }
    }

    if(!fl) { //if not a negative cycle
        for(int i = 0;i<N;i++) {  //printing all the shortest distance from the src
            cout << i << " " << dist[i] << endl;
        }
    }
    vy+=mpp[mq[j]]
    cout<<vy<<p;
    
    return 0;
}
