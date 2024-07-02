#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,x,sum = 0,total = 0;
	set<ll> s;
	cin>>n;
	vector<ll> ar(n+1,0),suf(n+1,0);
	vector<pair<ll,ll>> ans;
	for(ll i=1;i<=n;i++){
	cin>>ar[i];
	total+=ar[i];
	}
	for(ll i=n;i>=1;i--){
		s.insert(ar[i]);
		suf[i] = sz(s);
	}
	s.clear();
	for(ll i=1;i<=n-1;i++){
		sum+=ar[i];
		s.insert(ar[i]);
		if((sum == (i*(i+1))/2) && ((total - sum) == ((n-i)*(n-i+1))/2) && sz(s) == i && suf[i+1] == n-i)
		ans.pb({i,n-i});
	}
	cout<<sz(ans)<<"\n";
	for(auto i: ans)
	cout<<i.first<<" "<<i.second<<"\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

