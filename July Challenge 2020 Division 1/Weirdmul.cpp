#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 998244353;
ll fpow(ll b, ll e){
	b %= MOD;
	ll res = 1;
	while(e>0){
		if(e&1) res = (res*b) % MOD;
		b = (b*b) % MOD;
		e/=2; 
	}
	return res;
}
void solve(){
	ll n,a,x,ans=1;
	cin >> n >> x;
	vector<ll> pr(n+1,0);
	for(int i=0;i<n;i++)
	cin >> a;
	a %= MOD;
	x %= MOD;
	ll k=1;
	for(ll i=1;i<=n;i++){
		pr[i] = (pr[i-1] + (a*k)%MOD)%MOD;
		k = (k*x)%MOD;
	}
	for(ll i=n;i>=1;i--){
		ans = (ans * fpow(pr[i],2*(n-i+1)))%MOD;
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

