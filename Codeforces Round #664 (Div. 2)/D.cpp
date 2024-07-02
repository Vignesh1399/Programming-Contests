#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,d,m,num;
	cin >> n >> d >> m;
	vector<ll> good,bad;
	for(ll i=0;i<n;i++){
		cin >> num;
		if(num<=m)
		good.pb(num);
		else
		bad.pb(num);
	}
	sort(good.begin(),good.end());
	sort(bad.begin(),bad.end(),greater<ll>());
	vector<ll> prb(n+1,0),prg(n+1,0);
	for(ll i=0;i<sz(bad);i++){
		prb[i+1] = prb[i] + bad[i];
	}
	for(ll i=0;i<sz(good);i++){
		prg[i+1] = prg[i] + good[i];
	}
	ll ans=0;
	// Once we start using d goods, keep doing it till the end 
	for(ll nb=0;nb<=sz(bad);nb++){
		ll silent = max(0ll,(nb-1)*d); 
		if(silent>sz(good)+sz(bad)-nb) continue;
		ll goodneed = max(silent - (sz(bad) - nb),0ll);
		if(goodneed>sz(good)) continue;
		ans = max(ans,prb[nb] + prg[sz(good)] - prg[goodneed]);
	}
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

