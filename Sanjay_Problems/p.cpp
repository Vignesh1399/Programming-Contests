#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

void bfs(vector<ll> g[], queue<ll> &q, vector<ll> &d){
	while(!q.empty()){
		ll from = q.front();
		q.pop();
		for(auto to : g[from]){
			if(d[to] > -1) continue;
			d[to] = d[from] + 1;
			q.push(to);
		}
	}
}

void solve(){
	ll n,m,a,b,h;
	cin >> n >> m;
	vector<ll> g[n+1];
	vector<ll> d(n+1,-1);
	for(ll i=0;i<m;i++){
		cin  >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	cin >> h;
	queue<ll> q;
	for(ll i=0;i<h;i++){
		cin >> a;
		d[a] = 0;
		q.push(a);
	}
	bfs(g,q,d);
	for(ll i=1;i<=n;i++)
	cout<<d[i]<<" ";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

