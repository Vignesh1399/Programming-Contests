#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n,c;
	cin >> n >> c;
	vector<ll> x(n+1,0),y(n+1,0);
	map<ll,ll> m;
	ll g = 0;
	vector<vector<ll>> lines,cpts;
	for(ll i=1;i<=n;i++){
		cin >> x[i] >> y[i];
		ll d = x[i] - y[i];
		if(!m[d]){
			m[d] = ++g;
			lines.pb(vector<ll>());
			lines[m[d]-1].pb(x[i]);
		}
		else
		lines[m[d]-1].pb(x[i]);
	}
	ll cp = 0,op = 0;
	for(ll i=0;i<g;i++){
		m.clear();
		for(ll j=0;j<sz(lines[i]);j++){
			ll rem = (lines[i][j] % c + c)%c;
			if(!m[rem]){
				m[rem] = ++cp;
				cpts.pb(vector<ll>());
				cpts[m[rem]-1].pb(lines[i][j]);
			}
			else
			cpts[m[rem]-1].pb(lines[i][j]);
		}
	}
	cout << cp << " ";
	for(ll i=0;i<cp;i++){
		sort(cpts[i].begin(),cpts[i].end());
		ll mid = sz(cpts[i])/2;
		for(ll j=0;j<sz(cpts[i]);j++){
			op += abs(cpts[i][mid] - cpts[i][j])/c;
		}
		//cout << op << " ";
	}
	cout << op << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

