#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;


void solve(){
	ll n;
	cin>>n;
	vector<ll> ar(n,0);
	set<ll> s;
	for(ll i=0;i<n;i++){
	cin>>ar[i];
	s.insert(ar[i]);
	}
	cout<<sz(s)<<"\n";
	
}

int32_t main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

