#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll a,b,c;
	cin >> a >> b >> c;
	vector<ll> aa(2e4+1),bb(2e4+1),cc(2e4+1);
	vector<vector<ll>> par(2e4+1,vector<ll>(3,1e10)),idx(2e4+1,vector<ll> (3,0));
	for(ll i=1;i<=2e4;i++){
		cc[i] = abs(c - i);
		par[i][2] = cc[i];
		aa[i] = abs(a-i);
		bb[i] = abs(i-b);
	}
	for(ll i=1;i<=2e4;i++){
		for(ll j=i;j<=2e4;j+=i){
			//if(j%i !=0) continue;
			if(par[i][1]>bb[i]+par[j][2])
			idx[i][1] = j;
			par[i][1] = min(par[i][1],bb[i]+par[j][2]);
		}
	}
	ll ans = 1e10;
	for(ll i=1;i<=2e4;i++){
		for(ll j=i;j<=2e4;j+=i){
			//if(j%i !=0 ) continue;
			if(par[i][0]>aa[i]+par[j][1])
			idx[i][0] = j;
			par[i][0] = min(par[i][0],aa[i]+par[j][1]);
		}
		//ans = min(par[i][0],ans);
	}
	for(ll i=1;i<=2e4;i++){
		ans = min(par[i][0],ans);
	}
	cout << ans << '\n';
	for(ll i=1;i<=2e4;i++){
		if(par[i][0] == ans){
			cout << i << " "<< idx[i][0] <<" "<< idx[idx[i][0]][1]<<"\n";
			break;
		}
	}
	
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

