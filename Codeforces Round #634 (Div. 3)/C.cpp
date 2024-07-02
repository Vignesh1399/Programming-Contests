#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,a;
	map<ll,ll> m;
	cin >> n;
	set<ll> s;
	for(ll i=0;i<n;i++){
	cin>>a;
	m[a]++;
	s.insert(a);
	}
	ll sim = 0;
	for(auto i : m)
	sim = max(sim,i.second);
	
	ll ans = min(sim,sz(s)-1ll);
	ans = max(ans,min(sim-1ll,sz(s)+0ll));
	cout<<ans;
	cout<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}
 