#include<bits/stdc++.h>
#define int long long

using namespace std;

int a,b,n;

int fpb(int x,int y){
    if(y==0)return x;
    return fpb(y,x%y);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b;
    int s=fpb(a,b);
    cout<<s<<endl;
}
