#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 998244353;
vector<ll> fact;
void pre(ll n){
	fact.resize(n+1);
	fact[0] = 1;
	for(ll i=1;i<=n;i++)
	fact[i] = (fact[i-1] * i)% MOD;
}
void solve(){
	ll n,ans=1;
	cin >> n;
	pre(n);
	ans = fact[n];
	vector<pair<ll,ll>> ar(n);
	vector<ll> c1(n+1,0),c2(n+1,0);
	map<pair<ll,ll>,ll> m;
	for(ll i=0;i<n;i++){
		cin >> ar[i].F >> ar[i].S;
		c1[ar[i].F]++;
		c2[ar[i].S]++;
		m[{ar[i].F,ar[i].S}]++;
	}
	bool flag = 1;
	sort(ar.begin(),ar.end());
	ll cnt1 = 1,cnt2=1;
	for(ll i=1;i<=n;i++){
		cnt1 = (cnt1 * fact[c1[i]]) % MOD;
		cnt2 = (cnt2 * fact[c2[i]]) % MOD;
	}
	for(ll i=1;i<n;i++){
		if(ar[i].F>=ar[i-1].F && ar[i].S>=ar[i-1].S){
			
		}
		else
		flag = 0;  
	}
	ll cnt12 = flag;
	for(auto i : m){
		cnt12 = (cnt12 * fact[i.S]) % MOD;
	}
	ans = (ans - cnt1 + MOD) % MOD;
	ans = (ans - cnt2 + MOD) % MOD;
	ans = (ans + cnt12) % MOD;
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

