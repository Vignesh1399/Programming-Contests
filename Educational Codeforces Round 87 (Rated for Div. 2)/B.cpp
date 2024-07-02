#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll ans = 1e10;
	string s;
	cin >> s;
	vector<pair<ll,ll>> p;
	ll cnt = 0;
	for(ll i=0;s[i];i++){
		if(!i)
		cnt++;
		if(s[i] != s[i-1]){
			p.pb({s[i-1]-'0',cnt});
			cnt = 1;
		}
		else
		cnt++;
	}
	p.pb({s[sz(s)-1]-'0',cnt});
	for(ll i=0;i<sz(p)-2;i++){
		ll x = p[i].first;
		ll y = p[i+1].first;
		ll z = p[i+2].first;
		if(x+y+z == 6 && x!=y){
			ans = min(ans,2+p[i+1].second);
		}
	}
	
	if(ans<1e10)
	cout << ans << "\n";
	else
	cout << 0 << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

