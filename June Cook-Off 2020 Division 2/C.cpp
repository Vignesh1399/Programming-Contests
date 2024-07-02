#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

vector<ll> tans;

void dfs(ll s,vector<ll> g[], vector<bool> &v, vector<bool> &pp){
	v[s] = 1;
	tans.pb(s);
	for(auto i : g[s]){
		if(!v[i] && (pp[i] == pp[s]))
		dfs(i,g,v,pp);
	}
}

void solve(){
	ll n,m;
	tans.clear();
	cin >> n >> m;
	vector<ll> ar(n+1,0),br(n+1,0);
	vector<bool> pp(n+1,0);
	vector<bool> v(n+1,0);
	vector<ll> g[n+1];
	ll mnode = 0;
	ll am = 0,bm = 1;
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
	}
	for(ll i=1;i<=n;i++){
		ll a;
		cin >> a;
		br[i] = a;
		//cout << pp[i] << " ";
		ll den = (a*bm)/__gcd(a,bm);
		ll f1 = den/bm,f2 = den/a;
		if(am*f1<=f2*ar[i]){
			am = ar[i];
			bm = a;
		}
	}
	ll d = __gcd(am,bm);
	am/=d;
	bm/=d;
	for(ll i=1;i<=m;i++){
		ll a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(ll i=1;i<=n;i++){
		d = __gcd(ar[i],br[i]);
		ar[i]/=d;
		br[i]/=d;
		if(ar[i] == am && br[i] ==  bm){
			pp[i] = 1;
			mnode = i;
		}
	}
	vector<ll> ans;
	for(ll i=1;i<=n;i++){
		if(!v[i] && pp[i])
		dfs(i,g,v,pp);
		if(sz(tans)>sz(ans))
		ans = tans;
		tans.clear();
	}
	cout << sz(ans) << "\n";
	for(auto i : ans)
	cout << i << " ";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

