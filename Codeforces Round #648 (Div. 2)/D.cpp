#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(a) signed(a.size())
using namespace std;

ll di[4] = {1,-1,0,0};
ll dj[4] = {0,0,-1,1};

bool within(ll i, ll j, ll n, ll m){
	return (i>=1 && i<=n && j>=1 && j<=m);
}

void dfs(ll i, ll j, vector<vector<char>> &ar, vector<vector<bool>> &v, ll &g,ll n, ll m){
	v[i][j] = 1;
	if(ar[i][j] == '#')
	return ;
	if(ar[i][j] == 'G')
	++g;
	for(ll k=0;k<4;k++){
		ll ni = i + di[k], nj = j+dj[k];
		if(within(ni,nj,n,m) && !v[ni][nj])
		dfs(ni,nj,ar,v,g,n,m);
	}
}

void solve(){
	ll n,m;
	cin >> n >> m;
	ll ng,nb;
	ng = nb = 0;
	vector<vector<char>> ar(n+1,vector<char>(m+1,'0'));
	vector<vector<bool>> v(n+1,vector<bool>(m+1,0));
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			cin >> ar[i][j];
			if(ar[i][j] == 'G') ng++;
			if(ar[i][j] == 'B') nb++;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			for(ll k=0;k<4;k++){
				if(ar[i][j] != 'B') continue;
				ll ni = i+di[k],nj = j+dj[k];
				if(within(ni,nj,n,m) && !v[ni][nj] && ar[ni][nj] != 'B'){
					ar[ni][nj] = '#';
					v[ni][nj] = 1;
				}
			}
		}
	}
	ll gcount = 0;
	if(!v[n][m])
	dfs(n,m,ar,v,gcount,n,m);
	if(gcount == ng)
	cout << "YES";
	else
	cout <<"NO";
	cout << "\n";
}

int main() {
    FAST;
    ll t=1;
    cin>>t;
    while(t--) solve();	
    return 0;
}

