#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,m;
vector<pair<pair<int,int>,int>> bil;
vector<int> simpan;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int s,e,p;
        cin>>s>>e>>p;
        bil.push_back({{s,e},p});
        m=max(m,e);
    }
    sort(bil.begin(),bil.end());
    simpan.resize(m+1,0);
    for(int j=0;j<n;j++){
    for(int i=m;i>0;i--){
        if(bil[j].first.second<=i){
            simpan[i]=max(simpan[bil[j].first.first-1]+bil[j].second,simpan[i]);
        }
    }
    }
    cout<<simpan[m]<<endl;
}
