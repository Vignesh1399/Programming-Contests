#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 1e9 + 7;

ll power(ll a, ll b){
	ll res= 1;
	a %= MOD;
	while(b>0){
		if(b&1)
		res = (res * a) % MOD;
		a = (a*a)%MOD;
		b/=2;
	}
	return res;
}
void solve(){
	string s;
	cin >> s;
	ll ans=  0;
	for(ll i=0;s[i];i++){
		ll d = s[i]-'0';
		if(i == 0){
			ll val = (power(10,sz(s)) - 1 + MOD)%MOD;
			val = (val * power(9,MOD-2))%MOD;
			ans = (val * d)%MOD;
		}
		else{
			ll val =  (d * power(10,sz(s)-i-1))%MOD;
			if(i != sz(s)-1)
			val = (val+d)%MOD;
			else
			val = (d * (sz(s)-1))%MOD;
			ans = (ans + val)%MOD;
		}
	}
	cout << ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

