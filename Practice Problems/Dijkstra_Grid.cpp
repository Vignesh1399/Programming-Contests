#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;
ll di[] = {1,-1,0,0};
ll dj[] = {0,0,1,-1};
bool within(ll i, ll j, ll n){
	return (i>=1 && j>=1 && i<=n && j<=n);
}
vector<ll> mincost;
void dist(vector<ll> g[], vector<ll> &cost){
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
	mincost[1] = 0;
	q.push({0,1});
	while(!q.empty()){
		ll incl = q.top().second;
		ll d = q.top().first; 
		q.pop();
		if(mincost[incl] != d)
		continue;
		for(auto i : g[incl]){
			if(mincost[i]>mincost[incl]+cost[i]){
				mincost[i] = mincost[incl] + cost[i];
				q.push({mincost[i],i});
			}
		}
	}
}
void solve(){
	ll n;
	cin >> n;
	ll k = 1;
	vector<vector<ll>> ar(n+1,vector<ll>(n+1,0));
	vector<ll> cost(n*n+1,1e9);
	mincost.resize(n*n+1,1e9);
	ll N = n*n+1;
	vector<ll> g[N];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			cin >> cost[k];
			ar[i][j] = k++;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			for(ll m=0;m<4;m++){
				if(within(i+di[m],j+dj[m],n))
				g[ar[i][j]].push_back(ar[i+di[m]][j+dj[m]]);
			}
		}
	}
	dist(g,cost);
	ll ans = cost[1] + mincost[n*n];
	cout << ans << "\n";
}

int main() {
    FAST;
    ll t=1;
    //cin>>t;
    while(t--) solve();	
    return 0;
}

