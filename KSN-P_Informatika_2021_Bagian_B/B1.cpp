#include<bits/stdc++.h>
#define int long long

using namespace std;

int a,b,n;

int fpb(int x,int y){
    if(y==0)return x;
    return fpb(y,x%y);
}

int kpk(int x,int y){
    int hasil=x*y/fpb(x,y);
    return hasil;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>a>>b;
    int s=kpk(a,b);
    cout<<(s/a+s/b)<<endl;
}
