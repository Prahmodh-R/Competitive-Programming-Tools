//Dijkstra's with path
#include<bits/stdc++.h>
using namespace std;
 
 
int p[10000000];
int main(){
int n,m;
cin>>n>>m;
vector<pair<int,int> > g[n+1];
for(int  x,y,z,i=1;i<=m;i++){
	cin>>x>>y>>z;
	g[x].push_back({y,z});
	g[y].push_back({x,z});
}
set<pair<int,int> > s;
long long d[n+1];
fill(d+1,d+1+n,1e18);
d[1]=0;
s.insert({0,1});
while(!s.empty()){
	int v=s.begin()->second;
	s.erase(s.begin());
	for(int i=0;i<g[v].size();i++){
		int u=g[v][i].first;
		int q=g[v][i].second;
		if(d[v]+q<d[u]){
			s.erase({d[u],u});
			
			d[u]=d[v]+q;
			s.insert({d[u],u});
			p[u]=v;
		}
	}
	
}
if(d[n]==1e18){
	cout<<-1;
	return 0;
}
vector<int>a;
while(n>=1){
	a.push_back(n);
	n=p[n];
}
for(int i=a.size()-1;i>=0;i--){
	cout<<a[i]<<" ";
}
return 0;	
}
