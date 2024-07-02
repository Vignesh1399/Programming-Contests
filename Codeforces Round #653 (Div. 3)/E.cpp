#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,k,ans=1e10;
	cin >> n >> k;
	vector<ll> alice,bob,both,prb,pra,prboth;
	for(ll i=1;i<=n;i++){
		ll t,a,b;
		cin >> t >> a >> b;
		if(a && b)
		both.pb(t);
		else if(a)
		alice.pb(t);
		else if(b)
		bob.pb(t);
	}
	sort(alice.begin(),alice.end());
	sort(bob.begin(),bob.end());
	sort(both.begin(),both.end());
	for(ll i=0;i<sz(bob);i++){
		if(!i) prb.pb(bob[i]);
		else
		prb.pb(prb.back()+bob[i]);
	}
	for(ll i=0;i<sz(alice);i++){
		if(!i) pra.pb(alice[i]);
		else
		pra.pb(pra.back()+alice[i]);
	}
	for(ll i=0;i<sz(both);i++){
		if(!i) prboth.pb(both[i]);
		else
		prboth.pb(prboth.back()+both[i]);
	}
	if(sz(alice)>=k && sz(bob)>=k)
	ans = min(ans,prb[k-1]+pra[k-1]);
	for(ll i=0;i<k && i<sz(both);i++){
		ll x = k-i-1;
		if(sz(alice)>=x && sz(bob)>=x && x>0)
		ans = min(ans,prboth[i]+pra[x-1]+prb[x-1]);
		if(i==k-1)
		ans = min(ans,prboth[i]);
	}
	cout << ((ans==1e10)? -1 : ans) << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

