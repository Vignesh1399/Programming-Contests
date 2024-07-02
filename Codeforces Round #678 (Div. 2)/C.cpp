#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define F first 
#define S second 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll MOD = 1e9 + 7;
bool bs(vector<ll> &ar, ll x, set<ll> &s){
	ll left = 0;
	ll right = sz(ar);
	while(left<right){
		ll middle = (left + right)/2;
		s.insert(middle);
		if(ar[middle] <= x)
		left = middle + 1;
		else
		right = middle;
	}
	if(left>0 && ar[left-1] == x)
	return 1;
	return 0;
}
void solve(){
	ll n,x,pos;
	set<ll> s;
	cin >> n >> x >> pos;
	vector<ll> ar(n);
	for(ll i=0;i<n;i++)
	ar[i] = i;
	bs(ar,pos,s);
	s.erase(pos);
	ll ans = 1;
	ll less = x-1;
	ll g = n-x;
	for(auto i : s){
		//cout << i << " ";
		if(i<pos){
			ans = (ans * less) % MOD;
			less--;
		}
		else{
			ans = (ans * g) % MOD;
			g--;
		}
		less = max(less,0ll);
		g = max(g,0ll);
	}
	ll val = n - sz(s) - 1;
	for(ll i=1;i<=val;i++)
	ans = (ans * i) % MOD;
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

