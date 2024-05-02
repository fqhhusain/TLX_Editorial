#include<bits/stdc++.h>
#define int long long

using namespace std;

//perhatikan penamaan variabel

int n,m,s;
vector<vector<pair<int,int>>> edge;
vector<int> simpan;

void djikstra(){
	priority_queue<pair<int,int>,
	vector<pair<int,int>>,
	greater<pair<int,int>>> pq;
	pq.push({0,1});
	simpan[1]=0;
	while(!pq.empty()){
		int tv=pq.top().first;
		int tn=pq.top().second;
		pq.pop();
		if(simpan[tn]<tv)continue;
		for(auto u : edge[tn]){
			int xv=u.second;
			int xn=u.first;
			if(simpan[xn]>(simpan[tn]+xv)){
				simpan[xn]=simpan[tn]+xv;
				pq.push({simpan[xn],xn});
			}
		}
	}
	cout<<simpan[n+1]<<endl;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	simpan.resize(n+5,1e18);
	edge.resize(n+5);
	for(int i=1;i<=m;i++){
		int a,b,p;
		cin>>a>>b>>p;
		edge[a].push_back({b+1,p});
	}
	for(int i=1;i<=n;i++){
		edge[i].push_back({i+1,s});
		edge[i+1].push_back({i,0});
	}
	djikstra();
}
