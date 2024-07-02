#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 998244353;
vector<ll> fac(5e5+1,1),invf(5e5+1,1);

ll fpow(ll b, ll e){
	b %= MOD;
	ll res = 1;
	while(e){
		if(e&1)
		res = res * b % MOD;
		b = b * b %MOD;
		e/=2;
	}
	return res;
}
void pre(){
	for(ll i=1;i<=5e5;i++){
		fac[i] = fac[i-1] * i % MOD;
		invf[i] = fpow(fac[i],MOD-2);
	}
}

ll ncr(ll n, ll r){
	ll num = fac[n];
	ll den = invf[n-r] * invf[r] % MOD;
	return (num * den)%MOD;
}
void solve(){
	pre();
	ll n,k,ans=0;
	cin >> n >> k;
	for(ll i=1;i<=n;i++){
		ll d = n/i;
		if(k-1<=d-1)
		ans = (ans + ncr(d-1,k-1)) % MOD;
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

