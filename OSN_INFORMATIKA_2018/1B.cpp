#include<bits/stdc++.h>
#define int long long 

using namespace std;

string s;
int a,b,q;
vector<int> hasil;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	cin>>a>>b>>q;
	string ans="";
	if(q==0){
		if(__gcd(a,b+1)==1){
			cout<<"MUNGKIN"<<endl;
		}else{
			cout<<"TIDAK MUNGKIN"<<endl;
		}
		return 0;
	}
	while(a!=0){
		if(a>b){
			hasil.push_back(a/(b+1));
			a%=(b+1);
		}else{
			hasil.push_back(b/a);
			b%=a;
		}
	}
	if(b!=0){
		cout<<"TIDAK MUNGKIN"<<endl;
		return 0;
	}else{
		cout<<"MUNGKIN"<<endl;
	}
	reverse(hasil.begin(),hasil.end());
	for(int i=1;i<hasil.size();i++){
		hasil[i]+=hasil[i-1];
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		if(y>=hasil.back()){
			cout<<"DI LUAR BATAS"<<endl;
			continue;
		}
		int lower=lower_bound(hasil.begin(),hasil.end(),x)-hasil.begin();
		for(int j=0;j<y-x+1;j++){
			if((j+x)>=hasil[lower])lower++;
		cout<<(~lower & 1);
		}
		cout<<endl;
	}	
}
