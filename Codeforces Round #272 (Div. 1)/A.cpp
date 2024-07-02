#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 1e9 + 7;
ll power(ll a, ll e){
	a %= MOD;
	ll res = 1;
	while(e){
		if(e&1) res = (res * a) % MOD;
		a = (a*a) % MOD;
		e /= 2;
	}
	return res;
}
void solve(){
	ll a,b;
	cin >> a >> b;
	ll x = (b*(b-1)) % MOD;
	ll y = a;
	ll z = ((x*y)%MOD * power(2,MOD-2)) % MOD;
	x = (x*b)%MOD;
	y = (y*(a+1))%MOD;
	y = ((y*x)%MOD * power(4,MOD-2)) % MOD;
	ll ans = (z+y)%MOD;
	cout << ans; 
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

