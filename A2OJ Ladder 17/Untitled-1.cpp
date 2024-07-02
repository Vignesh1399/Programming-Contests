#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,ans=0;
	cin >> n;
	set<pair<ll,ll>> s;
	s.insert({0,0});
	vector<ll> ar(n+1,0);
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		auto it = s.upper_bound({ar[i],0ll});
		it--;
		s.insert({ar[i],(it->second) + 1});
	}
	for(auto i : s){
		ans = max(ans,i.second);
	}
	cout<<ans;
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

