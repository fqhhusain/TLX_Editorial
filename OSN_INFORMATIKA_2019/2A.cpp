#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> range;
vector<int> prefix;
vector<int> suffix;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		range.push_back({a,b});
		prefix.push_back(b);
		suffix.push_back(a);
	}
	sort(prefix.begin(),prefix.end());
	sort(suffix.begin(),suffix.end());
	for(int i=0;i<n;i++){
		int x=range[i].first;
		int y=range[i].second;
		int ans=n-1;
		if(x>1){
		auto lower=lower_bound(prefix.begin(),prefix.end(),x);
		ans-=(lower-prefix.begin());
	}
		if(y<m){
			auto upper=upper_bound(suffix.begin(),suffix.end(),y);
			ans-=(n-(upper-suffix.begin()));
		}
		cout<<ans<<endl;
	}
	
}
