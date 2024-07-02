#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

vector<ll> p_pow(1e5,1);
ll p = 31;
ll m = 1e9 + 9;

void precompute(){
	for(ll i=1;i<=1e5;i++)
	p_pow[i] = p_pow[i-1] * p % m;
}

void compute_hash(string &s, vector<ll> &hash){
	for(ll i=0;s[i];i++){
		hash[i+1] = (hash[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
	}
}


void solve(){
	string s;
	cin >> s;
	ll ans = 0;
	ll n = sz(s);
	vector<ll> hash(sz(s) + 1,0);
	compute_hash(s,hash);
	for(ll len=1;len<n/2;len++){
		ll v1 = (hash[len]);
		v1 = v1 * p_pow[n-0-1] % m;
		ll v2 = (hash[2*len]  + m - hash[len]) % m;
		v2 = v2 * p_pow[n-len-1] % m;
		ll new_len = n/2 - len;
		ll v3 = (hash[2*len + new_len] + m - hash[2*len]) % m;
		v3 = v3 * p_pow[n-(2*len)-1] % m;
		ll v4 = (hash[n] - hash[2*len + new_len] + m) % m;
		v4 = v4 * p_pow[n-(2*len+new_len)-1] % m;
		if(v1 == v2 && v3 == v4)
		ans++;
	}
	cout<<ans;
	cout<<"\n";
}

int main() {
    FAST;
    precompute();
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

