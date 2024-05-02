#include<bits/stdc++.h>
#define int long long

using namespace std;

int n;
multiset<int> bil;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        if(bil.size()==0){
            bil.insert(t);
        }else{
            if((*bil.rbegin())<t){
                bil.insert(t);
            }else{
                bil.erase(bil.find(*bil.lower_bound(t)));
                bil.insert(t);
            }
        }
    }
    cout<<bil.size()<<endl;
}
