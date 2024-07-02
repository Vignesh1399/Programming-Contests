#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 1e9 + 7;

ll power(ll b, ll e){
	ll res=  1;
	b %= MOD;
	while(e>0){
		if(e&1) res = (res*b)%MOD;
		b = (b*b)%MOD;
		e/=2;
	}
	return res;
}
void solve(){
	ll n;
	cin >> n;
	ll ans = 0,f=1;
	for(ll i=1;i<=n;i++){
		f = (f*i)%MOD;
	}
	ll p = power(2,n-1);
	ans = (f-p+MOD)%MOD;
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

