#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;



void z1bfs(ll i,ll j, vector<vector<char>> &ar, vector<vector<ll>> &d,ll n, ll m){
	d[i][j] = 0;
	deque <pair<ll,ll>> q;
	q.push_back({i,j});
	while(!q.empty()){
		pair<ll,ll> to = q.front();
		ll r = to.first;
		ll c = to.second;
		q.pop_front();
		if(r+1<=n){
			if(d[r+1][c] > d[r][c] + (ar[r][c] != ar[r+1][c])){
				d[r+1][c] = d[r][c] + (ar[r][c] != ar[r+1][c]);
				if(ar[r][c] != ar[r+1][c])
				q.push_back({r+1,c});
				else
				q.push_front({r+1,c});
			}
		}
		if(r-1>=1){
			if(d[r-1][c] > d[r][c] + (ar[r][c] != ar[r-1][c])){
				d[r-1][c] = d[r][c] + (ar[r][c] != ar[r-1][c]);
				if(ar[r][c] != ar[r-1][c])
				q.push_back({r-1,c});
				else
				q.push_front({r-1,c});
			}
		}
		if(c+1<=m){
			if(d[r][c+1] > d[r][c] + (ar[r][c] != ar[r][c+1])){
				d[r][c+1] = d[r][c] + (ar[r][c] != ar[r][c+1]);
				if(ar[r][c] != ar[r][c+1])
				q.push_back({r,c+1});
				else
				q.push_front({r,c+1});
			}
		}
		if(c-1>=1){
			if(d[r][c-1] > d[r][c] + (ar[r][c] != ar[r][c-1])){
				d[r][c-1] = d[r][c] + (ar[r][c] != ar[r][c-1]);
				if(ar[r][c] != ar[r][c-1])
				q.push_back({r,c-1});
				else
				q.push_front({r,c-1});
			}
		}
	}
}

void solve(){
	ll n,m;
	cin >> n >> m; 
	vector<vector<ll>> d(n+1,vector<ll>(m+1,1e9));
	vector<vector<char>> ar(n+1,vector<char>(m+1,'0'));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin >> ar[i][j];
		}
	}
	z1bfs(1ll,1ll,ar,d,n,m);
	cout << d[n][m] << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

