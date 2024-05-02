#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,k;
vector<int> patok;

int search(int id){
    int ans=0;
    int l=0;
    int r=n;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(patok[mid]<=id){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    patok.resize(n+1,0);
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        patok[i]=patok[i-1]+tmp;
    }
    for(int i=1;i<=k;i++){
        int tmp;
        cin>>tmp;
        cout<<search(tmp)<<endl;
    }
}
