#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,s,p;
vector<int> waktu;
map<string, vector<int>> virus;
vector<vector<int>> edge;
string sans;
int bans;

int dfs(int id){
    if(edge[id].size()==0)return waktu[id];
    int hasil=0;
    for(int i=0;i<edge[id].size();i++){
        hasil=max(hasil,dfs(edge[id][i]));
    }
    return hasil+waktu[id];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s>>p;
    waktu.resize(n+1);
    edge.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>waktu[i];
    }
    for(int i=1;i<=p;i++){
        string temp;
        int id;
        cin>>temp>>id;
        virus[temp].push_back(id);
    }
    for(int i=0;i<n-p;i++){
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
    }
    for(auto i : virus){
        for(int j=0;j<i.second.size();j++){
            int ans=dfs(i.second[j]);
            if(ans>bans){
                bans=ans;
                sans=i.first;
            }
            
        }
    }
    cout<<sans<<" "<<bans<<endl;
}
