#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> ar(n+1,0);
	vector<ll> pr(n+2,1e9);
	vector<ll> g[n+1];
	set<ll> s;
	for(ll i=1;i<=n;i++){
		cin >> ar[i];
		g[ar[i]].eb(i);
		s.insert(ar[i]);
	}
	if(sz(s) == 1){
		for(ll i=0;i<n;i++)
		cout << ar[1] << " ";
		return ;
	}
	for(ll i=1;i<=n;i++){
		ll d = 0;
		for(ll k=0;k<sz(g[i]);k++){
			if(k == 0){
				d = max(d,g[i][k] - 0ll);
			}
			else
			d = max(d,g[i][k]-g[i][k-1]);
		}
		if(sz(g[i])){
			d = max(d,n+1-g[i][sz(g[i])-1]);
			pr[d] = min(pr[d],i);
		}
	}
	for(ll i=1;i<=n;i++){
		pr[i] = min(pr[i-1],pr[i]);
		if(pr[i] == 1e9)
		cout << -1 << " ";
		else
		cout << pr[i] << " ";
	}
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

