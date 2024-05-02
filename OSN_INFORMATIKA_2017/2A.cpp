#include<bits/stdc++.h>
#define int long long

using namespace std;

string s;
int n,k;
vector<int> bil1;
vector<pair<int,int>> bil2;
vector<pair<int,int>> grup;
int ans;
vector<int> sisa;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	cin>>n>>k;
	bil1.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>bil1[i];
		bil2.push_back({bil1[i],i});
	}
	sort(bil2.begin(),bil2.end());
	int l=-1;
	int r=-1;
	for(int i=1;i<=n;i++){
	int pos=bil2[i-1].second;	
		if(l==-1 && r==-1){
			l=i;
			r=pos;
			continue;
		}
		if(r<i && r<pos){
			if(l!=r)grup.push_back({l,r});
			l=min(i,pos);
			r=max(i,pos);
		}else{
			r=max(r,pos);
			r=max(r,i);
		}
		
	}
	ans=0;
	if(l!=r)grup.push_back({l,r});
	int prev;
	for(int i=0;i<grup.size();i++){
		if(i){
			int tmp=grup[i].first-prev-1;
			prev=grup[i].second;
			sisa.push_back(tmp);
		}else{
			prev=grup[i].second;
		}
	ans+=(grup[i].second-grup[i].first+1);
	}
	sort(sisa.begin(),sisa.end());
	if(k>=grup.size()){
		ans+=(k-grup.size());
	}else{
		for(int i=0;i<(grup.size()-k);i++){
			ans+=sisa[i];
		}
	}
	cout<<ans<<endl;
}
