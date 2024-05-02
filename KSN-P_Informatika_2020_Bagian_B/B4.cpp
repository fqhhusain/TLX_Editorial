#include<bits/stdc++.h>
#define int long long

using namespace std;

int n;
vector<int> bil;
vector<int> simpan;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    bil.resize(n+1);
    simpan.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>bil[i];
    }
    for(int i=1;i<=n;i++){
        if(i==1){
            simpan[i]=0;
        }else{
        simpan[i]=simpan[i-1]+(bil[i]-bil[i-1])*(bil[i]- bil[i-1]);
        if(i>2){
            simpan[i]=min(simpan[i],simpan[i-2]+3*(bil[i]-bil[i-2])*(bil[i]-bil[i-2]));
            simpan[i]=min(simpan[i],simpan[i-1]+3*(bil[i]-bil[i-2])*(bil[i]-bil[i-2])+(bil[i-2]-bil[i-1])*(bil[i-2]- bil[i-1]));
        }
        }
    }
    cout<<simpan[n]<<endl;
}
