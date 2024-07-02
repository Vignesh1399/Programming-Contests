#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
bool ok = 1;
ll check(ll s, vector<ll> g[], vector<ll> &h, vector<pair<ll,ll>> &m, vector<ll> &p, vector<bool> &v){
	v[s] = 1;
	ll total = 0;
	ll tg=0,tb=0;
	for(auto i : g[s]){
		if(!v[i]){
			total += check(i,g,h,m,p,v);
			tg += m[i].first;
			tb += m[i].second;
		}
	}
	total += p[s];
	if((total+abs(h[s]))%2)
	ok = 0;
	m[s].first = (total+h[s])/2;
	m[s].second  = (total-h[s])/2;
	if(m[s].first<0 || m[s].second<0)
	ok = 0;
	ll left_bad = m[s].second - p[s];
	ll left_good = m[s].first + min(0ll,left_bad);
	left_bad = max(left_bad,0ll);
	if(left_bad+left_good>=tb){
		left_bad -= tb;
		left_good += min(left_bad,0ll);
		if(left_good<tg)
		ok = 0;
	}
	else
	ok = 0;
	return total;
}
void solve(){
	ok = 1;
	ll n,m;
	cin >> n >> m;
	vector<ll> p(n+1,0),h(n+1,0);
	vector<bool> v(n+1,0);
	vector<pair<ll,ll>> mood(n+1,{0,0});
	for(ll i=1;i<=n;i++)
	cin >> p[i];
	for(ll i=1;i<=n;i++)
	cin >> h[i];
	vector<ll> g[n+1];
	for(ll i=1;i<=n-1;i++){
		ll a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	// start, graph, happiness, mood, people, visited 
	check(1,g,h,mood,p,v);
	cout << ((ok)?"YES":"NO") << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

