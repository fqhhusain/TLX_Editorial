#include<bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

string s;

int n,k;

struct high{
	int ting;
	int ren;
	int sama;
	int tj;
	int ting2;
	int ren2;
	int sama2;
};
vector<int> faktor(100005);

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	cin>>n>>k;
	faktor[0]=1;
	for(int i=1;i<=100000;i++){
		faktor[i]=(i*faktor[i-1])%mod;
	}
	vector<high> je(k+1);
	for(int i=1;i<=k;i++){
		cin>>je[i].tj;
		je[i].ting=0;
		je[i].ren=0;
		je[i].sama=0;
		je[i].ting2=0;
		je[i].ren2=0;
		je[i].sama2=0;
	}
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		int tinggi=je[tmp].tj;
		if(i>tinggi){
			je[tmp].ting++;
		}else if(i<tinggi){
			je[tmp].ren++;
		}else{
			je[tmp].sama++;
		}
	}
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		int tinggi=je[tmp].tj;
		if(i>tinggi){
			je[tmp].ting2++;
		}else if(i<tinggi){
			je[tmp].ren2++;
		}else{
			je[tmp].sama2++;
		}
	}
	int ans=1;
	for(int i=1;i<=k;i++){
		if(je[i].ting==je[i].ren2){
			if(je[i].sama==1 && je[i].sama2==1){
				int tmp=1;
				tmp*=faktor[je[i].ting];
				tmp%=mod;
				tmp*=faktor[je[i].ren];
				tmp%=mod;
				tmp*=(je[i].ting+je[i].ren+je[i].sama);
				tmp%=mod;
				ans*=tmp;
				ans%=mod;
			}else{
				ans*=faktor[je[i].ting];
				ans%=mod;
				ans*=faktor[je[i].sama+je[i].ren];
				ans%=mod;
			}
		}else if(je[i].ting<je[i].ren2){
			if((je[i].ting+je[i].sama)==je[i].ren2){
				ans*=faktor[je[i].ren2];
				ans%=mod;
				ans*=faktor[je[i].ren];
				ans%=mod;
			}else{
				ans*=0;
			}
		}else{
			if(je[i].ting==(je[i].ren2+je[i].sama2)){
				ans*=faktor[je[i].ting];
				ans%=mod;
				ans*=faktor[je[i].ting2];
				ans%=mod;
			}else{
				ans*=0;
			}
		}
	}
	cout<<ans<<endl;
}
