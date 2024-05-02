#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,m;
vector<pair<int,int>> rendah;
vector<pair<int,int>> tinggi;
vector<int> simpan;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    simpan.resize(m+1,0);
    for(int i=0;i<n;i++){
        int h,k,d;
        cin>>h>>k>>d;
        if(d==1){
            tinggi.push_back({h,k});
        }
        if(d==0){
            rendah.push_back({h,k});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<rendah.size();j++){
            if(rendah[j].first<=i){
                simpan[i]=max(simpan[i],simpan[i-rendah[j].first]+rendah[j].second);
            }
        }
    }
    for(int j=0;j<tinggi.size();j++){
        for(int i=m;i>=1;i--){
            if(tinggi[j].first<=i){
                simpan[i]=max(simpan[i],simpan[i-tinggi[j].first]+tinggi[j].second);
            }
        }
    }
    cout<<simpan[m]<<endl;
}
